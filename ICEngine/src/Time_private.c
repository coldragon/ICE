﻿#include "hdr/Time_private.h"
#include <SDL2/SDL.h>
#include "hdr/TypesCore.h"

extern ICE_Game game;

void ICE_TimeStart()
{
	game.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
	game.time.ticksEllapsed = game.time.actual - game.time.last; // calculate nb of ticks ellapsed
	game.time.delta = (double)game.time.ticksEllapsed / 1000.0; // update the time.delta
	//if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
	if (game.time.ticksEllapsed)
		game.time.fps = (double)(1000.0 / game.time.ticksEllapsed); // calculate fps
}

void ICE_TimeEnd()
{
	game.time.last = game.time.actual;
}