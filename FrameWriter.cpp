//
// Created by yuitora . on 13/08/2020.
//

#include "FrameWriter.h"
#include "cap_ffmpeg_impl.h"


FrameWriter::FrameWriter(const char *filename, const char *codec_name, double fps, int width, int height,
                            const char *ffmpegcmd) {
    this->width = width;
    this->height = height;
    this->fps = fps;
    this->step = width * n_channel * sizeof(uint8_t);
    this->n_channel = 3;

    this->data = new uint8_t[width * height * 3];
    for (int i = 0; i < width * height * 3; i++)
        this->data[i] = 0;

    framewriter = cvCreateVideoWriter_FFMPEG(filename, codec_name, fps, width, height, ffmpegcmd, data);
    if(framewriter)
        initialized = true;
}

int FrameWriter::write_frame() {
    if (!initialized)
        return 1;
    return framewriter->writeFrame();
}

void FrameWriter::close_video() {
    if (!initialized)
        return;
    cvReleaseVideoWriter_FFMPEG(&framewriter);
    free(data);
    initialized = false;
}

FrameWriter::FrameWriter() = default;

bool FrameWriter::is_opened() {
    return initialized;
}

FrameWriter::~FrameWriter() {

}
