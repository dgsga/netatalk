test_sources = [afpd_files, 'test.c', 'subtests.c', 'afpfunc_helpers.c']

deps = [kerberos, libgcrypt, mysqlclient]

afpdtest = executable(
    'afpdtest',
    test_sources,
    include_directories: inc,
    dependencies: deps,
    c_args: ['-DAPPLCNAME', messagedir, uamdir, confdir, statedir],
    link_with: libatalk,
)

test_sh = find_program('test.sh')

test('test1', test_sh)
test('test2', afpdtest)
