project(
    'netatalk',
    'c',
    version: '3.1.18',
    license: 'GPLv2',
    default_options: ['warning_level=3', 'c_std=c11'],
    meson_version: '>=1.1.0',
)

cc = meson.get_compiler('c')

####################
# Global variables #
####################

cdata = configuration_data()
cpu = host_machine.cpu_family()
fs = import('fs')
host_os = host_machine.system()
supported_cpus = ['aarch64', 'x86_64']
supported_oses = 'darwin'
version = meson.project_version()

#########
# Paths #
#########

prefix = get_option('prefix')
exec_prefix = get_option('prefix')
bindir = prefix / get_option('bindir')
datadir = prefix / get_option('datadir')
includedir = prefix / get_option('includedir')
libdir = prefix / get_option('libdir')
localstatedir = prefix / get_option('localstatedir')
mandir = prefix / get_option('mandir')
pkgconfdir = prefix / get_option('sysconfdir')
sbindir = prefix / get_option('sbindir')

##################
# Compiler flags #
##################

# Global

add_global_arguments('-D_U_=__attribute__((unused))', language: 'c')

# Per target

ad = '-D_PATH_AD="' + bindir + '/ad"'
afpd = '-D_PATH_AFPD="' + sbindir + '/afpd"'
cnid_dbd = '-D_PATH_CNID_DBD="' + sbindir + '/cnid_dbd"'
cnid_metad = '-D_PATH_CNID_METAD="' + sbindir + '/cnid_metad"'
confdir = '-D_PATH_CONFDIR="' + pkgconfdir + '/"'
messagedir = '-DSERVERTEXT="' + localstatedir + '/netatalk/msg/"'
statedir = '-D_PATH_STATEDIR="' + localstatedir + '/netatalk/"'
uamdir = '-D_PATH_AFPDUAMPATH="' + libdir + '/netatalk/"'
dversion = '-DVERSION="' + version + '"'

############
# Includes #
############

inc = include_directories(
    '.',
    'etc/afpd',
    'include',
    prefix / 'opt/db/include',
)

#############
# Libraries #
#############

db = cc.find_library('db', dirs: prefix / 'opt/berkeley-db/lib', required: true)
pam = cc.find_library('pam', required: true)

################
# Dependencies #
################

dbus = dependency('dbus-1', required: true)
dbusglib = dependency('dbus-glib-1', required: true)
gthread = dependency('gthread-2.0', required: true)
gssapi = dependency('gss', required: true)
kerberos = dependency('kerberos', required: true)
ldap = dependency('ldap', required: true)
libevent = dependency('libevent', required: true)
libgcrypt = dependency('libgcrypt', required: true)
libiconv = dependency('iconv', method: 'system', required: true)
mysqlclient = dependency('mysqlclient', required: true)
threads = dependency('threads', required: true)
wolfssl = dependency('wolfssl', required: true)
zeroconf = dependency('system', required: true)

############
# Programs #
############

brew = find_program('brew', required: true)
xsltproc = find_program('xsltproc', required: true)

#################
# Configuration #
#################

cdata.set('bindir', bindir)
cdata.set('compiled_backends', '"dbd last mysql"')
cdata.set('DBUS_DAEMON_PATH', bindir)
cdata.set('DEFAULT_CNID_SCHEME', '"dbd"')
cdata.set('DOCBOOK_ROOT', prefix / 'opt/docbook-xsl/docbook-xsl')
cdata.set('EA_MODULES', '"ad | sys"')
cdata.set('exec_prefix', prefix)
cdata.set('includedir', includedir)
cdata.set('libdir', libdir)
cdata.set('localstatedir', localstatedir)
cdata.set('NETATALK_VERSION', meson.project_version())
cdata.set('PATH_NETATALK_LOCK', '"/var/run/netatalk.pid"')
cdata.set('PERL', '/usr/bin/perl')
cdata.set('pkgconfdir', pkgconfdir)
cdata.set('prefix', prefix)
cdata.set('sbindir', sbindir)
cdata.set('version', meson.project_version())

configure_file(
    input: 'config.h.meson',
    output: 'config.h',
    configuration: cdata,
)

subdir('libatalk')
subdir('bin')
subdir('config')
subdir('contrib')
subdir('distrib')
subdir('include')
subdir('etc')
subdir('doc')

if get_option('build-tests')
    subdir('test')
endif

#########################
# Configuration summary #
#########################

# Build environment

summary_info = {
    'Build directory': meson.current_build_dir(),
    'Source path': meson.current_source_dir(),
}
summary(summary_info, bool_yn: true, section: 'Build environment:')

# Directories

summary_info = {
    'Installation prefix': get_option('prefix'),
    'Executable directory': bindir,
    'Header file directory': get_option('prefix') / get_option('includedir'),
    'Library directory': libdir,
    'Manual page directory': mandir,
    'System executable directory': sbindir,
}
summary(summary_info, bool_yn: true, section: 'Directories:')

# Compilation information

summary_info = {
    'host CPU': cpu,
    'host endianness': build_machine.endian(),
    'C compiler': cc.get_id(),
}
summary(summary_info, bool_yn: true, section: 'Compilation:')

# Configuration summary

summary({'Netatalk version': version}, section: 'Configuration Summary:')
summary_info = {
    '  Extended Attributes': true,
    '  Spotlight support': 'native',
}
summary(summary_info, bool_yn: true, section: '  AFP:')

summary_info = {
    '  Kerberos V': true,
    '  DHX': 'PAM',
    '  DHX2': 'PAM',
}
summary(summary_info, bool_yn: true, section: '  UAMS:')

summary_info = {
    '  AFP stats via dbus': true,
    '  dtrace probes': true,
    '  GSSAPI support': true,
    '  Kerberos support': true,
    '  LDAP support': true,
    '  Zeroconf support': true,
}
summary(summary_info, bool_yn: true, section: '  Options:')

summary_info = {
    '  dbus daemon path': bindir / 'dbus-daemon',
    '  dbus system directory': pkgconfdir / 'dbus-1/system.d',
    '  init directory': 'Library/LaunchDaemons',
    '  Netatalk lockfile': '/var/run/netatalk.pid',
}
summary(summary_info, bool_yn: true, section: '  Paths:')

summary_info = {'  Docbook': true}
summary(summary_info, bool_yn: true, section: '  Documentation:')


