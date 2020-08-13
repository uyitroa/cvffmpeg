//#include "cap_ffmpeg_impl.h"
#include "FrameWriter.h"

int main(int argc, char **argv) {
    const int width = 1000;
    const int height = 1000;

    const char *codec_name = "libx264";
    FrameWriter test("test.mp4", codec_name, 60, width, height, "-preset ultrafast -crf 30");
    for (int x = 0; x < 100; x++) {
        test.data[x * test.width * test.n_channel + x * test.n_channel] = 255;
        test.write_frame();
    }
    test.close_video();
    return 0;
}