/*

#include <stdio.h>
#include "hdr/Core.h"
#include "hdr/Game.h"
#include "hdr/Render.h"

ICE_Game GameCreate()
{
	ICE_Game game = ICE_CreateApp("ICE", 512, 512);
	ICE_CreateTextureManager(&game);
	ICE_CreateTexture(&game, &game.tex_man[0], "res/img/logo.png", 0);
	return game;
}

void GameUpdate(ICE_Game *game)
{
	ICE_InputReturn(game->input);
	ICE_TextureRender(game->render, &game->tex_man[0].texturepack[0], NULL, NULL);
}

void GameDestroy(ICE_Game *game)
{
	ICE_DestroyGame(game);
}

int main(int argc, char* args[])
{
	return ICE_GameLoop(GameCreate, GameUpdate, GameDestroy);;
}

*/