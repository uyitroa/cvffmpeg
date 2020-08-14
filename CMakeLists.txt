cmake_minimum_required(VERSION 3.12)
project(cvffmpeg)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
link_directories(lib)

add_executable(cvffmpeg main.cpp cap_ffmpeg_impl.h cap_ffmpeg_legacy_api.h ffmpeg_codecs.h FrameWriter.cpp FrameWriter.h)
target_link_libraries(cvffmpeg avcodec avutil avformat swresample swscale)