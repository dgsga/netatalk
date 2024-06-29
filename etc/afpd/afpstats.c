/*
 * Copyright (c) 2013 Frank Lahm <franklahm@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <gio/gio.h>

#include <atalk/compat.h>
#include <atalk/errchk.h>
#include <atalk/logger.h>
#include <atalk/server_child.h>

#include "afpstats_obj.h"
//#include "afpstats_service_glue.h"

/*
 * Beware: this struct is accessed and modified from the main thread
 * and from this thread, thus be careful to lock and unlock the mutex.
 */
static server_child_t *childs;
static GDBusNodeInfo *introspection_data = NULL;

static gpointer afpstats_thread(gpointer _data)
{
    GDBusConnection *bus;
    GDBusProxy *bus_proxy;
    GError *error = NULL;
    GMainContext *ctxt;
    GMainLoop *thread_loop;
    guint request_name_result;
    sigset_t sigs;

    /* Block all signals in this thread */
    sigfillset(&sigs);
    pthread_sigmask(SIG_BLOCK, &sigs, NULL);

    ctxt = g_main_context_new();
    thread_loop = g_main_loop_new(ctxt, FALSE);

    if (!(bus = g_bus_get_sync(G_BUS_TYPE_SYSTEM,
                               NULL,
                               &error))) {
        LOG(log_error, logtype_afpd,"Couldn't connect to system bus: %s", error->message);
        return NULL;
    }

    if (!(bus_proxy = g_dbus_proxy_new_sync(bus,
                                            G_DBUS_PROXY_FLAGS_NONE,
                                            NULL, /* GDBusInterfaceInfo */
                                            "org.freedesktop.DBus",
                                            "/org/freedesktop/DBus",
                                            "org.freedesktop.DBus",
                                            NULL, /* GCancellable */
                                            &error))) {
        LOG(log_error, logtype_afpd,"Couldn't create bus proxy");
        return NULL;
    }

    if (!g_dbus_proxy_call_sync(bus_proxy,
                                "RequestName",
                                g_variant_new("(as)", "org.netatalk.AFPStats", 0),
                                G_DBUS_CALL_FLAGS_NONE,
                                -1, /* timeout */
                                NULL,
                                &error)) {
        LOG(log_error, logtype_afpd, "Failed to acquire DBUS name: %s", error->message);
        return NULL;
    }

    static const gchar introspection_xml[] =
        "<node>"
        "  <interface name='org.netatalk.AFPStats'>"
        "    <method name='GetUsers'>"
        "      <arg name='ret' type='as' direction='out'/>"
        "    </method>"
        "  </interface>"
        "</node>";

    introspection_data = g_dbus_node_info_new_for_xml (introspection_xml, NULL);
    g_assert (introspection_data != NULL);

    AFPStatsObj *obj = g_object_new(AFPSTATS_TYPE_OBJECT, NULL);

    g_dbus_connection_register_object(bus,
                                      "/org/netatalk/AFPStats",
                                      introspection_data->interfaces[0],
                                      NULL,
                                      G_OBJECT(obj),
                                      NULL,
                                      &error);

    g_main_loop_run(thread_loop);
    return thread_loop;
}

static void my_glib_log(const gchar *log_domain,
                        GLogLevelFlags log_level,
                        const gchar *message,
                        gpointer user_data)
{
    LOG(log_error, logtype_afpd, "%s: %s", log_domain, message);
}

server_child_t *afpstats_get_and_lock_childs(void)
{
    pthread_mutex_lock(&childs->servch_lock);
    return childs;
}

void afpstats_unlock_childs(void)
{
    pthread_mutex_unlock(&childs->servch_lock);
}

int afpstats_init(server_child_t *childs_in)
{
    GThread *thread;

    childs = childs_in;
    dbus_g_thread_init();
    (void)g_log_set_default_handler(my_glib_log, NULL);

    thread = g_thread_new("afpstats", afpstats_thread, NULL);

    return 0;
}
