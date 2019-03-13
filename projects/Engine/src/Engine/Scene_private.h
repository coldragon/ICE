﻿#ifndef DEF_ICE_SCENE_PRIVATE_H
#define DEF_ICE_SCENE_PRIVATE_H

#include "Color.h"
#include "Camera_private.h"
#include "EntityManager_private.h"

struct ICE_Scene
{
	ICE_Bool				quit;
	ICE_Bool				isPaused;
	ICE_Bool				isFree;

	void					(*func_create)(void);
	void					(*func_update)(void);
	void					(*func_destroy)(void);

	void					(*func_OnResume)(void);
	void					(*func_OnPause)(void);

	// Camera
	ICE_Camera				camera;

	// Label
	// ICE_LabelManager 	label_mngr;

	// Gui
	// ICE_GuiManager	gui_mngr;

	// Entity
	ICE_EntityManager		entity_mngr;

	// Data
	ICE_ID					data_nb;
	void**					data;

	ICE_Color				background;

	struct ICE_Scene *		parent;

}; typedef struct ICE_Scene ICE_Scene;

#endif