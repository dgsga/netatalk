uams_pam_sources = ['uams_pam.c']

uams_pam = shared_module(
    'uams_pam',
    uams_pam_sources,
    include_directories: inc,
    dependencies: pam,
    name_prefix: '',
    name_suffix: 'so',
    install: true,
    install_dir: libdir / 'netatalk',
)

uams_pam = static_library(
    'uams_pam',
    uams_pam_sources,
    include_directories: inc,
    dependencies: pam,
    name_prefix: '',
    install: true,
    install_dir: libdir / 'netatalk',
)

uams_dhx_pam_sources = ['uams_dhx_pam.c']

uams_dhx_pam = shared_module(
    'uams_dhx_pam',
    uams_dhx_pam_sources,
    include_directories: inc,
    dependencies: [nettle, pam, wolfssl],
    c_args: '-Wno-macro-redefined',
    name_prefix: '',
    name_suffix: 'so',
    install: true,
    install_dir: libdir / 'netatalk',
)

install_symlink(
    'uams_dhx.so',
    install_dir: libdir / 'netatalk',
    pointing_to: 'uams_dhx_pam.so',
)

uams_dhx_pam = static_library(
    'uams_dhx_pam',
    uams_dhx_pam_sources,
    include_directories: inc,
    dependencies: [nettle, pam, wolfssl],
    c_args: '-Wno-macro-redefined',
    name_prefix: '',
    install: true,
    install_dir: libdir / 'netatalk',
)



uams_dhx2_pam_sources = ['uams_dhx2_pam.c']

uams_dhx2_pam = shared_module(
    'uams_dhx2_pam',
    uams_dhx2_pam_sources,
    include_directories: inc,
    dependencies: [pam, libgcrypt],
    name_prefix: '',
    name_suffix: 'so',
    install: true,
    install_dir: libdir / 'netatalk',
)

install_symlink(
    'uams_dhx2.so',
    install_dir: libdir / 'netatalk',
    pointing_to: 'uams_dhx2_pam.so',
)

uams_dhx2_pam = static_library(
    'uams_dhx2_pam',
    uams_dhx2_pam_sources,
    include_directories: inc,
    dependencies: [pam, libgcrypt],
    name_prefix: '',
    install: true,
    install_dir: libdir / 'netatalk',
)

uams_gss_sources = ['uams_gss.c']

uams_gss = shared_module(
    'uams_gss',
    uams_gss_sources,
    include_directories: inc,
    dependencies: kerberos,
    name_prefix: '',
    name_suffix: 'so',
    install: true,
    install_dir: libdir / 'netatalk',
)

uams_gss = static_library(
    'uams_gss',
    uams_gss_sources,
    include_directories: inc,
    dependencies: kerberos,
    name_prefix: '',
    install: true,
    install_dir: libdir / 'netatalk',
)
