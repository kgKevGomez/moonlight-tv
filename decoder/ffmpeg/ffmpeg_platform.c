#include <stddef.h>
#include "stream/api.h"

bool decoder_check_ffmpeg(PDECODER_INFO info)
{
    info->valid = true;
    info->accelerated = false;
    info->audio = false;
    return true;
}