﻿#ifndef DEF_ICE__CAMERA
#define DEF_ICE__CAMERA

#include "../Maths/TypesMaths.h"
#include "../Core/TypesCore.h"

/**
 * \brief Set Camera position to a Vector
 * \param vect New Camera position
 */
void ICE_Camera_SetPos(ICE_Vect vect);

/**
 * \brief Move Camera to a coordinate and move it by a value R
 * \param vect Coordinate where Camera go
 * \param r Value/Distance to move the camera
 */
void ICE_Camera_MovePos(ICE_Vect vect, ICE_Float r);

/**
 * \brief Shift Camera position by a vector
 * \param Dvect Vector to add
 */
void ICE_Camera_ShiftPos(ICE_Vect Dvect);


/**
 * \brief Convert a ICE_Box in World Coordinate to Screen Coordinate
 * \param rect Box in World Coordinate to convert
 * \return Box in Screen Coordinate
 */
ICE_Box ICE_Camera_WorldScreen(ICE_Box rect);

/**
* \brief Convert a ICE_Box in Screen Coordinate to World Coordinate
* \param rect Box in Screen Coordinate to convert
* \return Box in World Coordinate
*/
ICE_Box ICE_Camera_ScreenWorld(ICE_Box rect);

/**
 * \brief Return a Vector with Camera Coordinate
 * \return 
 */
ICE_Vect ICE_Camera_GetPos(ICE_State* state_);

#endif