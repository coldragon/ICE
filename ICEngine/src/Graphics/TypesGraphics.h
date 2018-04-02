﻿#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS
#include <SDL2/SDL.h>
#include "../Maths/TypesMaths.h"

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
/**
* \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True) or -1(ICE_BoolNone).
* The last one is for some function where the use of ICE_BoolNone is documented
*/
typedef int ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0
#define ICE_BOOLNONE -1	
#define ICE_BoolNone -1
#define ICE_boolnone -1

#endif

/**
 * \brief Color in the Engine, it's a uint32_t for 8 bits per value (R, G, B, A)
 */
typedef Uint32 ICE_Color;

/**
 * \brief Texture struct handling sdl texture
 */
struct ICE_Texture
{
	ICE_Bool exist;
	int w, h;
	SDL_Texture* handle;

}; typedef struct ICE_Texture ICE_Texture;

/**
 * \brief Texture Manager
 */
struct ICE_TextureManager
{

	ICE_Bool isFree;
	unsigned int texture_size;
	unsigned int texture_contain;
	ICE_Texture* texture;

}; typedef struct ICE_TextureManager ICE_TextureManager;

typedef enum
{
	ICE_RECTANGLE,
	ICE_GUI_BACKGROUND_FIXED,
	ICE_GUI_BACKGROUND_FREE

} ICE_GuiType;

typedef struct
{
	ICE_Bool exist;
	ICE_Bool have_texture_defined;

	int texture_nb;
	int old_texture_nb;
	int texturemanager_nb;
	int old_texturemanager_nb;
	ICE_Box box;
	ICE_Box old_box;

	ICE_GuiType type;
	ICE_Texture texture_cache;

} ICE_Gui;

typedef struct
{
	ICE_Bool isFree;

	int gui_size;
	int gui_contain;
	ICE_Gui* gui;

} ICE_GuiManager;

#endif