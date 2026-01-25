/* miniaudio.c
 * Author(s): David Reid, Skylar Koningin
 * Description: A small, custom-coded library of my most common functions
 * Indetation Style: Allman
 */

#define MA_NO_COREAUDIO
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

ma_result result;
ma_engine engine;

void audio_setup(void) 
{
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS)
    {
        printf("Failed to initialize audio engine.\n");
    }
}