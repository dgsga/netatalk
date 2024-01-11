netatalk_sources = [
  'afp_mdns.c',
  'afp_zeroconf.c',
  'netatalk.c']

executable('netatalk',
            netatalk_sources,
            include_directories : inc,
            link_with : libatalk,
            dependencies : [mysqlclient, zeroconf, libevent],
            c_args : [confdir,
                      statedir,
                      afpd,
                      cnid_metad],
            install : true,
            install_dir : sbindir)
