#ifndef DEF_ICE_FONT
#define DEF_ICE_FONT

#include "Game.h"
#include <stdio.h>

void iceFontLoad(iceGame* game, char *path);
void iceFontDraw(iceGame* game, char* text, int size, iceVect vect);

#endif