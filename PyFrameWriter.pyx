# distutils: language = c++

from cpython cimport Py_buffer


# Declare the class with cdef
cdef extern from "FrameWriter.h":
	cdef cppclass FrameWriter:

		int width;
		int height;
		int n_channel;
		unsigned char *data;

		FrameWriter();
		FrameWriter(const char *filename, const char *codec_name, double fps, int width, int height, const char *ffmpegcmd);
		void close_video();
		int write_frame();

cdef class PyFrameWriter:
	cdef FrameWriter c_writer  # Hold a C++ instance which we're wrapping

	def __cinit__(self, const char *filename, const char *codec_name, double fps, int width, int height, const char *ffmpegcmd):
		self.c_writer = FrameWriter(filename, codec_name, fps, width, height, ffmpegcmd)

	def close_video(self):
		return self.c_writer.close_video()

	def write_frame(self):
		return self.c_writer.write_frame()

	def __getbuffer__(self, Py_buffer *buffer, int flags):
		cdef Py_ssize_t itemsize = sizeof(unsigned char)

		pylen = self.c_writer.width * self.c_writer.height * self.c_writer.n_channel

		buffer.buf = self.c_writer.data
		buffer.format = 'b'                     # uint8_t
		buffer.internal = NULL                  # see References
		buffer.itemsize = itemsize
		buffer.len = <Py_ssize_t>pylen
		buffer.ndim = 1
		buffer.obj = self
		buffer.readonly = 0
		buffer.shape = &buffer.len
		buffer.strides = &buffer.itemsize
		buffer.suboffsets = NULL                # for pointer arrays only

	def __releasebuffer__(self, Py_buffer *buffer):
		pass
