#include "cap_ffmpeg_impl.h"


int main() {
    CvVideoWriter_FFMPEG* writer = cvCreateVideoWriter_FFMPEG("test.mp4", 27, 60, 1920, 1080, 1);
    cvReleaseVideoWriter_FFMPEG(&writer);
    return 0;
}