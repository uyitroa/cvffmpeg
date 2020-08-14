#include "FrameWriter.h"

int main() {
    const int width = 1920;
    const int height = 1080;
    uint8_t img[width * height * 3];

    for (unsigned char &i : img)
        i = 0;

    FrameWriter fr("test.mp4", "libx264", 60, width, height, "-preset ultrafast", img);

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 100; x++) {
            int index = y * width * 3 + x * 3;
            img[index] = 255;
            img[index+1] = 255;
            img[index+2] = 0;
            fr.write_frame();
        }
    }

    fr.close_video();
}