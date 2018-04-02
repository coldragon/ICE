﻿#include "Audio.h"
#include <SDL2/SDL_mixer.h>

void ICE_Audio_Init()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(20);
	Mix_VolumeMusic(5);
}

void ICE_Audio_Close()
{
	Mix_CloseAudio();
}