from distutils.core import setup, Extension

mue_hash_module = Extension('mue_hash',
                            sources=['muemodule.c',
                                     'mue.c',
                                     'sha3/blake.c',
                                     'sha3/bmw.c',
                                     'sha3/groestl.c',
                                     'sha3/jh.c',
                                     'sha3/keccak.c',
                                     'sha3/skein.c',
                                     'sha3/cubehash.c',
                                     'sha3/echo.c',
                                     'sha3/luffa.c',
                                     'sha3/simd.c',
                                     'sha3/shavite.c'],
                            include_dirs=['.', './sha3'])

setup(name='mue_hash',
      version='0.0.1',
      description='Binding for MUE X11 proof of work hashing.',
      ext_modules=[mue_hash_module])
