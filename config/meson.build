afp_conf_exists = fs.exists(pkgconfdir/'afp.conf')

afp_conf = configure_file(input: 'afp.conf.tmpl',
                                 output: 'afp.conf',
                                 configuration: cdata)

if afp_conf_exists
else
  install_data(afp_conf,
    install_dir : pkgconfdir)
endif

install_data('extmap.conf',
  install_dir : pkgconfdir)

install_data('netatalk-dbus.conf',
  install_dir : prefix/'etc/dbus-1/system.d')

install_data('README',
  install_dir : localstatedir/'netatalk')

install_data('README',
  install_dir : localstatedir/'netatalk/CNID')
