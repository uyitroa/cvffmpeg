#include "cap_ffmpeg_impl.h"

bool is_valid_codec(const char* codec_name) {
    AVCodec *codec = avcodec_find_encoder_by_name(codec_name);
    return codec != nullptr;
}

int main() {
    const int width = 1920;
    const int height = 1080;

    const char *codec_name = "libx264";
    AVCodec *codec = avcodec_find_encoder_by_name(codec_name);
    if (!codec) {
        fprintf(stderr, "Codec '%s' not found\n", codec_name);
        exit(1);
    }

//    /* initialize libavcodec, and register all codecs and formats */
//    av_register_all();
//
//    /* Enumerate the codecs*/
//    AVCodec * codec1 = av_codec_next(NULL);
//    while(codec1 != NULL)
//    {
//        if (codec1->type == AVMEDIA_TYPE_VIDEO) {
//            if (is_valid_codec(codec1->name)) {
//                printf("%s: %s\n", codec1->name, codec1->long_name);
//            }
//        }
//        codec1 = av_codec_next(codec1);
//    }


    CvVideoWriter_FFMPEG* writer = cvCreateVideoWriter_FFMPEG("test.mp4", codec_name, 60, width, height, 1);

    uint8_t data[width * height * 3];

    for (int x = 0; x < width * height * 3; x++)
        data[x] = 0;

    int step = width * 3 * sizeof(uint8_t);

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 2000; x++) {
            data[y * width * 3 + x * 3] = 255;
            cvWriteFrame_FFMPEG(writer, data, step, width, height, 3, 0);
        }
    }

    cvReleaseVideoWriter_FFMPEG(&writer);
    return 0;
}