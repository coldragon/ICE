#include "Input_private.h"

#include "TypesCore.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

void ICE_Input_Return()
{
	// Reset one time event
	for(int i = 0; i < 512; i++)
	{
			CORE.window.input.OnPress[i] = 0;
			CORE.window.input.OnRelease[i] = 0;
	}

	CORE.window.input.leftclic_OnPress = 0;
	CORE.window.input.leftclic_OnRelease = 0;
	CORE.window.input.rightclic_OnPress = 0;
	CORE.window.input.rightclic_OnRelease = 0;

	while (SDL_PollEvent(&CORE.event))
	{
		switch (CORE.event.type)
		{
		case SDL_QUIT:
			CORE.window.input.quit = 1;
			break;
		case SDL_KEYDOWN:
			
			if (CORE.window.input.Pressed[CORE.event.key.keysym.scancode] == 0)
			{
				CORE.window.input.Pressed[CORE.event.key.keysym.scancode] = 1;
				CORE.window.input.OnPress[CORE.event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
			if (CORE.window.input.Pressed[CORE.event.key.keysym.scancode] == 1)
			{
				CORE.window.input.Pressed[CORE.event.key.keysym.scancode] = 0;
				CORE.window.input.OnRelease[CORE.event.key.keysym.scancode] = 1;
			}	
			break;
		case SDL_MOUSEWHEEL:
			if (CORE.event.wheel.y > 0)
				CORE.window.input.wheelup = 1;
			if (CORE.event.wheel.y < 0)
				CORE.window.input.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (CORE.event.button.button == SDL_BUTTON_LEFT)
			{
				if (CORE.window.input.leftclic_pressed == 0)
				{
					CORE.window.input.leftclic_pressed = 1;
					CORE.window.input.leftclic_OnPress = 1;
				}
			}
			if (CORE.event.button.button == SDL_BUTTON_RIGHT)
			{
				if (CORE.window.input.rightclic_pressed == 0)
				{
					CORE.window.input.rightclic_pressed = 1;
					CORE.window.input.rightclic_OnPress = 1;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (CORE.event.button.button == SDL_BUTTON_LEFT)
			{
				if (CORE.window.input.leftclic_pressed == 1)
				{
					CORE.window.input.leftclic_pressed = 0;
					CORE.window.input.leftclic_OnRelease = 1;
				}
			}
			if (CORE.event.button.button == SDL_BUTTON_RIGHT)
			{
				if (CORE.window.input.rightclic_pressed == 1)
				{
					CORE.window.input.rightclic_pressed = 0;
					CORE.window.input.rightclic_OnRelease = 1;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			CORE.window.input.mousex = CORE.event.motion.x;
			CORE.window.input.mousey = CORE.event.motion.y;
			break;
		case SDL_DROPFILE:
			CORE.window.input.filedrop = CORE.event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (CORE.event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				CORE.window.input.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				CORE.window.input.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				CORE.window.w = CORE.event.window.data1;
				CORE.window.h = CORE.event.window.data2;
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (CORE.event.wheel.y == 0)
		{
			CORE.window.input.wheelup = 0;
			CORE.window.input.wheeldown = 0;
		}
	}
}