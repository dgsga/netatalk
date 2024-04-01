launch_daemon = configure_file(
    input: 'com.netatalk.daemon.plist.in',
    output: 'com.netatalk.daemon.plist',
    configuration: cdata,
)

install_data(sources: launch_daemon, install_dir: '/Library/LaunchDaemons')

initscript = configure_file(
    input: 'netatalkd.in',
    output: 'netatalkd',
    configuration: cdata,
)

install_data(initscript, install_dir: bindir)

meson.add_install_script('launchctl.sh')
