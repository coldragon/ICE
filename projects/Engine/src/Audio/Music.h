﻿#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"
#include "../Graphics/Camera.h"
#include "../Framework/Macrotools.h"

void ICE_MusicManager_Init();
void ICE_MusicManager_Destroy();

#define ICE_Music_Load_MEM(S) ICE_Music_Load_RW(SDL_RWFromConstMem(S, S##_length));\
	if(ICE_Music_GetLastLoaded() != (ICE_ID)-1)\
		ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Music loaded from memory ID(%ld)\n Token(##S##)), ICE_Music_GetLastLoaded());\
	else\
		ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(Music didn t loaded from token : ##S));\

// MUSIC
ICE_TextureID ICE_Music_GetLastLoaded();
ICE_MusicID ICE_Music_Load(char* path);
ICE_Music ICE_Music_Build_RW(SDL_RWops * ops);
ICE_MusicID ICE_Music_Load_RW(SDL_RWops * ops);

void ICE_Music_Clear(ICE_ID music_);
void ICE_Music_Destroy(ICE_ID music_);
ICE_Music* ICE_Music_Get(ICE_ID music_);

// PLAY

int ICE_Music_Play(ICE_ID music_, ICE_Float volume_);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif