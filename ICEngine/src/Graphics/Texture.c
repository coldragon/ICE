﻿#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Log.h"

#include "Texture_private.h"
#include "../Framework/Memory_.h"

extern ICE_Asset ASSET;
extern ICE_Game GAME;

/* TEXTUREMANAGER */

void ICE_TextureManager_Init() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTUREMNGR_SIZE;
	texture_manager.texture = ICE_Calloc(ICE_DEFAULT_TEXTUREMNGR_SIZE, sizeof(ICE_Texture));
	ASSET.texture_mngr = texture_manager;
	ICE_Log(ICE_LOG_SUCCES, "Init TextureManager");
}

void ICE_TextureManager_Destroy()
{
	for (ICE_ID i = 0; i < ASSET.texture_mngr.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(ASSET.texture_mngr.texture);
	ASSET.texture_mngr.texture = NULL;
	ICE_Log(ICE_LOG_SUCCES, "Free TextureManager");
}

/* TEXTURE */

ICE_Texture ICE_Texture_Build(char* path_)
{
	ICE_Texture texture_temp = ICE_Texture_LoadFromFile(path_);
	texture_temp.exist = 1;
	int w, h;
	texture_temp.w = texture_temp.handle->base_w; texture_temp.h = texture_temp.handle->base_h;
	GPU_SetBlending(texture_temp.handle, GPU_BLEND_ADD);
	return texture_temp;
}

ICE_ID ICE_Texture_Load(char* path_) 
{

	ICE_EntityID avaible_slot = 0;
	ICE_Bool no_avaible_slot = ICE_False;

	for (ICE_EntityID i = 0; i < ASSET.texture_mngr.texture_contain; i++)
	{
		if (ASSET.texture_mngr.texture[i].exist == ICE_False)
		{
			avaible_slot = i;
			no_avaible_slot = ICE_True;
			break;
		}
	}
	if (!no_avaible_slot)
	{
		avaible_slot = ASSET.texture_mngr.texture_contain;
		ASSET.texture_mngr.texture_contain++;
	}

	ASSET.texture_mngr.texture[avaible_slot] = ICE_Texture_Build(path_);
	ASSET.texture_mngr.texture[avaible_slot].id = avaible_slot;

	ICE_Log(ICE_LOG_SUCCES, "Load Texture %d from \"%s\"", avaible_slot, path_);
	
	if (ASSET.texture_mngr.texture_size <= ASSET.texture_mngr.texture_contain) 
	{
		ASSET.texture_mngr.texture = ICE_Realloc(ASSET.texture_mngr.texture, sizeof(ICE_Texture)*(ASSET.texture_mngr.texture_size * 2));
		ASSET.texture_mngr.texture_size *= 2;
	}
	
	return avaible_slot;
}

void ICE_Texture_Destroy(ICE_ID texture_) 
{
	ASSET.texture_mngr.texture[texture_].exist = ICE_False;
	GPU_FreeImage(ASSET.texture_mngr.texture[texture_].handle);
	ICE_Log(ICE_LOG_SUCCES, "Destroy Texture %d", texture_);
}

void ICE_Texture_Free(ICE_Texture * texture_)
{
	GPU_FreeImage(texture_->handle);
}

unsigned int ICE_Texture_GetW(ICE_ID texture_)
{
	return ASSET.texture_mngr.texture[texture_].w;
}

unsigned int ICE_Texture_GetH(ICE_ID texture_)
{
	return ASSET.texture_mngr.texture[texture_].h;
}

ICE_Texture * ICE_Texture_Get(ICE_ID texture_)
{
	return &ASSET.texture_mngr.texture[texture_];
}