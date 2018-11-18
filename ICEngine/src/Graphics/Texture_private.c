#include "Texture_private.h"

//#define STB_IMAGE_IMPLEMENTATION
//#include "../External/stb/stb_image.h"

#define SDL_STBIMAGE_IMPLEMENTATION 1
#include "../External/stb/SDL_stbimage.h"

#include "../Core/TypesCore.h"

#include "../Core/SDL2_Includer.h"
#include ICE_INCLUDE_SDL2

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"
#include "../Core/Converter_private.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
ICE_Uint32 static const rmask = 0xff000000;
ICE_Uint32 static const gmask = 0x00ff0000;
ICE_Uint32 static const bmask = 0x0000ff00;
ICE_Uint32 static const amask = 0x000000ff;
#else
ICE_Uint32 static const rmask = 0x000000ff;
ICE_Uint32 static const gmask = 0x0000ff00;
ICE_Uint32 static const bmask = 0x00ff0000;
ICE_Uint32 static const amask = 0xff000000;
#endif

ICE_Texture ICE_Texture_LoadFromFile(char *path)
{
	SDL_Surface* surf;
	/*
	int req_format = STBI_rgb_alpha;
	int width, height, orig_format;
	unsigned char* data = stbi_load(path, &width, &height, &orig_format, req_format);
	if (data == NULL) {
		SDL_Log("ERROR : Can't load image : %s", stbi_failure_reason());
		surf = NULL;
	}
	else {
		int depth, pitch;
		ICE_Uint32 pixel_format;
		if (req_format == STBI_rgb) {
			depth = 24;
			pitch = 3 * width;
			pixel_format = SDL_PIXELFORMAT_RGB24;
		}
		else {
			depth = 32;
			pitch = 4 * width;
			pixel_format = SDL_PIXELFORMAT_RGBA32;
		}

		surf = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, width, height,
			depth, pitch, pixel_format);
	}
	*/

	

	surf = STBIMG_Load(path);

	if (surf == NULL) {
		SDL_Log("CRITICAL : Can't create Surface from image : %s", SDL_GetError());
		//stbi_image_free(data);

	#include "../Raw/Error.c"
		surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
			ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
			rmask, gmask, bmask, amask);
	}


	ICE_Texture text = {0};
	text.handle = GPU_CopyImageFromSurface(surf);
	if (text.handle == NULL)
		SDL_Log("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text.w = surf->w; text.h = surf->h;

	SDL_FreeSurface(surf);
	//stbi_image_free(data);
	return text;
}

int ICE_Texture_RenderEx(const ICE_Texture *tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle) 
{
	GPU_SetAnchor(tex->handle, 0.0f, 0.0f);
	   
	if (!src && dst)
	{
		GPU_Rect dst_gpu = { dst->x, dst->y, dst->w, dst->h };
		GPU_BlitRectX(tex->handle, NULL, CORE.window.render, &dst_gpu, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}
	else if (src && !dst)
	{
		GPU_Rect src_gpu = { src->x, src->y, src->w, src->h };
		GPU_BlitRectX(tex->handle, &src_gpu, CORE.window.render, NULL, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}
	else if (!src && !dst)
	{
		GPU_Rect src_gpu = { src->x, src->y, src->w, src->h };
		GPU_Rect dst_gpu = { dst->x, dst->y, dst->w, dst->h };
		GPU_BlitRectX(tex->handle, NULL, CORE.window.render, NULL, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}
	else
	{
		GPU_Rect src_gpu = { src->x, src->y, src->w, src->h };
		GPU_Rect dst_gpu = { dst->x, dst->y, dst->w, dst->h };
		GPU_BlitRectX(tex->handle, &src_gpu, CORE.window.render, &dst_gpu, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}

	return 0;
}

int ICE_Texture_RenderExCentered(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle)
{
	GPU_SetAnchor(tex->handle, 0.5f, 0.5f);

	if (!src && dst)
	{
		GPU_Rect dst_gpu = { dst->x, dst->y, dst->w, dst->h };
		GPU_BlitRectX(tex->handle, NULL, CORE.window.render, &dst_gpu, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}
	else if (src && !dst)
	{
		GPU_Rect src_gpu = { src->x, src->y, src->w, src->h };
		GPU_BlitRectX(tex->handle, &src_gpu, CORE.window.render, NULL, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}
	else if (!src && !dst)
		GPU_BlitRectX(tex->handle, NULL, CORE.window.render, NULL, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	else
	{
		GPU_Rect src_gpu = { src->x, src->y, src->w, src->h };
		GPU_Rect dst_gpu = { dst->x, dst->y, dst->w, dst->h };
		GPU_BlitRectX(tex->handle, &src_gpu, CORE.window.render, &dst_gpu, angle, 0.5f, 0.5f, GPU_FLIP_NONE);
	}

	return 0;
}