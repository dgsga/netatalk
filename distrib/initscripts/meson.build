init_dir = '/Library/LaunchDaemons'

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

if not fs.exists(init_dir / 'com.netatalk.daemon.plist')
    meson.add_install_script(
        find_program('launchctl'),
        'load',
        '-w',
        init_dir / 'com.netatalk.daemon.plist',
    )
endif
