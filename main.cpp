#include "FrameWriter.h"

int main() {
    const int width = 1920;
    const int height = 1080;
    const int n_channel = 4;
    uint8_t img[width * height * n_channel];

    for (unsigned char &i : img)
        i = 0;

    FrameWriter fr("test.mp4", "libx264", 60, width, height, "-preset ultrafast", img);

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 100; x++) {
            int index = y * width * n_channel + x * n_channel;
            img[index] = 255;
            img[index+1] = 255;
            img[index+2] = 0;
            fr.write_frame();
        }
    }

    fr.close_video();
//    std::vector<const char *> codecname = getcodecname();
//    std::vector<const char *> codeclongname = getcodeclongname();
//
//    for(int i = 0; i < codecname.size(); i++)
//        printf("%s: %s\n", codecname[i], codeclongname[i]);
}