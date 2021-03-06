﻿#include "Window.h"
#include "TypesCore.h"
#include ICE_INCLUDE_SDL2
#include "../External/stb/SDL_stbimage.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../External/stb/stb_image_write.h"
#include "../Framework/Log.h"
#include "../Framework/Memory_.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

void ICE_Window_SetSize(int w, int h)
{
	SDL_SetWindowSize(CORE.window.handle, w, h);
	CORE.window.w = w; CORE.window.h = h;
}

void ICE_Window_SetResizable(ICE_Bool yn)
{
	SDL_SetWindowResizable(CORE.window.handle, yn);
}

void ICE_Window_SetFullscreen(int yn)
{
	SDL_SetWindowFullscreen(CORE.window.handle, yn);
}

void ICE_Window_SetTitle(const char *title)
{
	SDL_SetWindowTitle(CORE.window.handle, title);
}

void ICE_Window_SetIcon(char * path)
{
	if (!path) 
	{
#include "../Ressources/raw/Icon.c"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (ice_raw_img_icon.bytes_per_pixel == 3) ? 8 : 0;
		Uint32 rmask = 0xff000000 >> shift;
		Uint32 gmask = 0x00ff0000 >> shift;
		Uint32 bmask = 0x0000ff00 >> shift;
		Uint32 amask = 0x000000ff >> shift;
#else // little endian, like x86
		Uint32 rmask = 0x000000ff;
		Uint32 gmask = 0x0000ff00;
		Uint32 bmask = 0x00ff0000;
		Uint32 amask = (ice_raw_img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif

		SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_icon.pixel_data, ice_raw_img_icon.width,
			ice_raw_img_icon.height, ice_raw_img_icon.bytes_per_pixel * 8, ice_raw_img_icon.bytes_per_pixel*ice_raw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(CORE.window.handle, icon);

		SDL_FreeSurface(icon);
	}
	else
	{

		SDL_Surface *icon = STBIMG_Load(path);

		if (icon == NULL)
			ICE_Log(ICE_LOGTYPE_ERROR, "ICE_Window_SetIcon : %s", SDL_GetError);
		
		SDL_SetWindowIcon(CORE.window.handle, icon);
		SDL_FreeSurface(icon);
	}
}

int ICE_Window_GetW()
{
	return (int)CORE.window.w;
}
int ICE_Window_GetH()
{
	return (int)CORE.window.h;
}