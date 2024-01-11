util_sources = [
  'cnid.c',
  'fault.c',
  'ftw.c',
  'getiface.c',
  'gettok.c',
  'locking.c',
  'logger.c',
  'netatalk_conf.c',
  'queue.c',
  'server_child.c',
  'server_ipc.c',
  'server_lock.c',
  'socket.c',
  'strdicasecmp.c',
  'unix.c']

build_args = [
  confdir,
  messagedir,
  uamdir,
  statedir,
  dversion]

libutil = static_library('util',
                          util_sources,
                          include_directories : inc,
                          c_args : build_args,
                          install : false)
