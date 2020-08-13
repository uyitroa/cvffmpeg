from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(name="zzz", cmdclass = {'build_ext': build_ext},
	ext_modules=[
		Extension("test1", sources=["PyFrameWriter.pyx", "FrameWriter.cpp"], extra_compile_args=["-std=c++11"],
                language="c++",
                include_dirs = ['include'],
        libraries = ['avcodec', 'avutil', 'avformat', 'swresample', 'swscale'],
        library_dirs = ['lib'])])