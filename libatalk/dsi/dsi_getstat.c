/*
 *
 * Copyright (c) 1997 Adrian Sun (asun@zoology.washington.edu)
 * All rights reserved. See COPYRIGHT.
 */

#include "config.h"

#include <arpa/inet.h>
#include <string.h>

#include <atalk/dsi.h>

/* return the status and then delete the connection. most of the
 * fields are already set. */
void dsi_getstatus(DSI *dsi)
{
  dsi->header.dsi_flags = DSIFL_REPLY;
  /*dsi->header.dsi_command = DSIFUNC_STAT;*/
  dsi->header.dsi_data.dsi_code = dsi->header.dsi_reserved = 0;

  memcpy(dsi->commands, dsi->status, dsi->statuslen);
  dsi->cmdlen = dsi->statuslen;
  dsi_send(dsi);
}
