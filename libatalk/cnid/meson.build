subdir('dbd')
subdir('last')
subdir('mysql')

cnid_sources = ['cnid_init.c', 'cnid.c']

libcnid = static_library(
    'cnid',
    cnid_sources,
    include_directories: inc,
    dependencies: mysqlclient,
    link_whole: [libcnid_dbd, libcnid_last, libcnid_mysql],
    install: false,
)
