# Makefile.am for libatalk/

SUBDIRS = acl adouble asp atp bstring compat cnid dsi iniparser nbp netddp talloc util unicode vfs

lib_LTLIBRARIES = libatalk.la

libatalk_la_SOURCES = dummy.c

libatalk_la_CFLAGS = \
	@PTHREAD_CFLAGS@

libatalk_la_LIBADD  = \
	@WRAP_LIBS@ @ACL_LIBS@ @PTHREAD_LIBS@ @MYSQL_LIBS@ \
	acl/libacl.la \
	adouble/libadouble.la	\
	asp/libasp.la \
	atp/libatp.la \
	bstring/libbstring.la \
	cnid/libcnid.la \
	compat/libcompat.la	\
	dsi/libdsi.la		\
	iniparser/libiniparser.la \
	nbp/libnbp.la \
	netddp/libnetddp.la \
	unicode/libunicode.la \
	util/libutil.la		\
	vfs/libvfs.la

libatalk_la_DEPENDENCIES = \
	acl/libacl.la \
	adouble/libadouble.la	\
	asp/libasp.la \
	atp/libatp.la \
	bstring/libbstring.la \
	cnid/libcnid.la \
	compat/libcompat.la	\
	dsi/libdsi.la		\
	iniparser/libiniparser.la \
	nbp/libnbp.la \
	netddp/libnetddp.la \
	unicode/libunicode.la \
	util/libutil.la		\
	vfs/libvfs.la
	
if WITH_SPOTLIGHT
SUBDIRS += talloc
libatalk_la_LIBADD += talloc/libtalloc.la
libatalk_la_DEPENDENCIES += talloc/libtalloc.la 
endif

