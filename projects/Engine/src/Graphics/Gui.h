﻿#ifndef DEF_ICE_GUI
#define DEF_ICE_GUI

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"
#include "../Core/State.h"

#define ICE_DEFAULT_GUI_MNGR_SIZE 4

/* GUI */

ICE_ID ICE_Gui_Create(ICE_State * state_, const ICE_Box box_, ICE_GuiType types_);
void ICE_Gui_Clear(ICE_Gui * label_);
void ICE_Gui_Destroy(ICE_Gui * ptr);

/* GUI GET */

ICE_Gui * ICE_Gui_Get(ICE_State *state, ICE_GuiID gui);
ICE_Box ICE_Gui_GetBox(ICE_Gui * gui);

/* GUI SET */

void ICE_Gui_SetTexture(ICE_Gui * gui_ptr_, int texture_id_);
void ICE_Gui_SetBox(ICE_Gui * gui, ICE_Box box);
void ICE_Gui_SetPos(ICE_Gui * gui, ICE_Vect pos);
void ICE_Gui_SetSize(ICE_Gui * gui, ICE_Vect vect);
void ICE_Gui_SetType(ICE_Gui * gui, ICE_GuiType type);

#endif
