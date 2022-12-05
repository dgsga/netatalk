project('netatalk', 'c',
  version : '3.1.18',
  license : 'GPLv2',
  default_options : ['warning_level=3', 'c_std=c11'],
  meson_version : '>=1.1.0'
)

cc = meson.get_compiler('c')

add_global_arguments('-D_U_=__attribute__((unused))', language : 'c')

supported_cpus = ['aarch64', 'x86_64']
supported_oses = 'darwin'

cdata = configuration_data()
fs = import('fs')
prefix = get_option('prefix')
version = meson.project_version()

inc = include_directories('.',
                          'etc/afpd',
                          prefix/'opt/db/include',
                          prefix/'opt/libressl/include',
                          'include')

bindir = prefix/'bin'
datadir = prefix/'share'
includedir = prefix/'include'
libdir = prefix/'lib'
localstatedir = prefix/'var'
mandir = prefix/'share/man'
pkgconfdir = prefix/'etc'
sbindir = prefix/'sbin'

ad = '-D_PATH_AD="' + bindir + '/ad"'
afpd = '-D_PATH_AFPD="' + sbindir + '/afpd"'
cnid_dbd = '-D_PATH_CNID_DBD="' + sbindir + '/cnid_dbd"'
cnid_metad = '-D_PATH_CNID_METAD="' + sbindir + '/cnid_metad"'
confdir = '-D_PATH_CONFDIR="' + pkgconfdir + '/"'
messagedir = '-DSERVERTEXT="' + localstatedir + '/netatalk/msg/"'
statedir = '-D_PATH_STATEDIR="' + localstatedir + '/netatalk/"'
uamdir = '-D_PATH_AFPDUAMPATH="' + libdir + '/netatalk/"'
dversion = '-DVERSION="' + version + '"'

cdata.set('bindir', bindir)
cdata.set('compiled_backends', '"dbd last mysql"')
cdata.set('DBUS_DAEMON_PATH', bindir)
cdata.set('DEFAULT_CNID_SCHEME', '"dbd"')
cdata.set('DOCBOOK_ROOT', prefix/'opt/docbook-xsl/docbook-xsl')
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

configure_file(input : 'config.h.meson',
               output : 'config.h',
               configuration : cdata)

db = cc.find_library('db', dirs : prefix/'opt/berkeley-db/lib', required: true)
crypto = cc.find_library('crypto', dirs : prefix/'opt/libressl/lib', required: true)
kerberos = cc.find_library('krb5', required : true)
ldap = cc.find_library('ldap', required : true)
pam = cc.find_library('pam', required : true)
zeroconf = cc.find_library('system', required : true)

dbus = dependency('dbus-1', required : true)
dbusglib = dependency('dbus-glib-1', required : true)
glib = dependency('glib-2.0', required : true)
libevent = dependency('libevent', required : true)
libgcrypt = dependency('libgcrypt', required : true)
libiconv = dependency('iconv', method : 'system', required : true)
mysqlclient = dependency('mysqlclient', required : true)
threads = dependency('threads', required : true)

brew = find_program('brew', required : true)
xsltproc = find_program('xsltproc', required : true)

build_manual = get_option('BUILD_MANUAL')
run_tests = get_option('RUN_TESTS')

subdir('libatalk')
subdir('bin')
subdir('config')
subdir('contrib')
subdir('distrib')
subdir('include')
subdir('etc')
subdir('doc')

if run_tests
	subdir('test')
endif


