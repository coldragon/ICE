#include "Core_private.h"

#include "Time_private.h"
#include "TypesCore.h"
#include "Label.h"
#include "MacOS_.h"

#include "../Framework/Terminal_private.h"
#include "../Framework/Log.h"

#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2
#include ICE_INCLUDE_SDL2_TTF

#include <stdio.h>

#include "../Audio/Audio.h"
#include "../Audio/Sound.h"
#include <string.h>
#include "Core.h"
#include "../Framework/Random.h"
#include "../External/physfs/physfs.h"
#include "Version.h"

ICE_Core CORE = { 0 } ;
extern ICE_Game GAME;
extern ICE_Config CONFIG;

int ICE_Core_Init() 
{
#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif

	// Term Save before log
	ICE_Term_SaveColor();
	ICE_Term_HideCursor();
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Core Init ...");

	// SDL
	if(SDL_Init(SDL_INIT_VIDEO) == 0)
		ICE_Log(ICE_LOGTYPE_SUCCES, "Init SDL");
	else
		ICE_Log(ICE_LOGTYPE_SUCCES, "Init SDL : %s", SDL_GetError());
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	// SDL_Mixer
	ICE_Audio_Init();

	// SDL_TTF
	if (TTF_Init() == 0)
		ICE_Log(ICE_LOGTYPE_SUCCES, "Init SDL_ttf");
	else
		ICE_Log(ICE_LOGTYPE_ERROR, "Init SDL_ttf : %s", TTF_GetError());
	
	// Random
	ICE_Random_Init();

	// SDL_gfx
	ICE_Time_Init();

	// Physfs
	if(PHYSFS_init(CONFIG.argv[0]))
		ICE_Log_Succes("PHYSFS_init() succes");
	else
		ICE_Log_Error("PHYSFS_init() error : %s", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));

	// Path
	char * basePath = SDL_GetBasePath();
	char * dataPath = SDL_GetPrefPath(CONFIG.editor_name, CONFIG.product_name);
	strcpy(CORE.basePath, basePath);
	strcpy(CORE.dataPath, dataPath);
	SDL_free(basePath);
	SDL_free(dataPath);

	// Hardware Info
	ICE_Log(ICE_LOGTYPE_INFO, "");
	ICE_Log_printf("\n Platform: %s\n", SDL_GetPlatform());
	ICE_Log_printf(" CPU: %d CORE %d MB L1\n", SDL_GetCPUCount(), SDL_GetCPUCacheLineSize());
	ICE_Log_printf(" RAM: %d MB \n", SDL_GetSystemRAM());
	ICE_Log_printf(" Screen Count : %d\n\n", SDL_GetNumVideoDisplays());
	
	// ICE Version
	ICE_Log_printf(" ICE Compiled : %s\n", ICE_Core_GetCompiledVersion());
	ICE_Log_printf(" ICE Linked : %s\n\n", ICE_Core_GetLinkedVersion());
	
	// SDL Version print
	ICE_Log_printf(" SDL Version : \n");
	ICE_Log_printf(" Compiled: %d.%d.%d\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
	SDL_version linked;
	SDL_GetVersion(&linked);
	ICE_Log_printf(" Linked: %d.%d.%d\n", linked.major, linked.minor, linked.patch);
	
	// SDL_TTF Version print
	const SDL_version *link_version_ttf = TTF_Linked_Version();
	ICE_Log_printf(" SDL_ttf Version : \n");
	ICE_Log_printf(" Compiled: %d.%d.%d\n", SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
	ICE_Log_printf(" Linked: %d.%d.%d\n", link_version_ttf->major, link_version_ttf->minor, link_version_ttf->patch);
	
	// SDL_Mixer Version print
	const SDL_version *link_version_mixer = Mix_Linked_Version();
	ICE_Log_printf(" SDL_mixer Version : \n");
	ICE_Log_printf(" Compiled: %d.%d.%d\n", SDL_MIXER_MAJOR_VERSION, SDL_MIXER_MINOR_VERSION, SDL_MIXER_PATCHLEVEL);
	ICE_Log_printf(" Linked: %d.%d.%d\n\n", link_version_mixer->major, link_version_mixer->minor, link_version_mixer->patch);

	// PhysFS Version
	PHYSFS_Version link_version_physf;
	PHYSFS_getLinkedVersion(&link_version_physf);
	ICE_Log_printf(" PhysFS Version : \n");
	ICE_Log_printf(" Compiled: %d.%d.%d\n", PHYSFS_VER_MAJOR, PHYSFS_VER_MINOR, PHYSFS_VER_PATCH);
	ICE_Log_printf(" Linked: %d.%d.%d\n\n", link_version_physf.major, link_version_physf.minor, link_version_physf.patch);

	// SDL path
	ICE_Log_printf(" Execution Path: %s\n", CORE.basePath);
	ICE_Log_printf(" Data Path: %s\n", CORE.dataPath);

#if defined(__APPLE__)
	//ICE_MacOS_SetWorkingDirectory(SDL_GetBasePath());
	ICE_Log_printf("MacOS Resources Directory: %s\n\n", ICE_MacOS_GetResourcesDirectory());
#endif
	puts("");
	ICE_Log(ICE_LOGTYPE_FINISH, "Core Init");
	ICE_Log_Line();

	return 0;
}

int ICE_Core_Quit() 
{
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Core Quit ...");
	
	// SDL
	TTF_Quit();
	ICE_Log(ICE_LOGTYPE_SUCCES, "Quit SDL_TTF");
	ICE_Audio_Close();
	ICE_Log(ICE_LOGTYPE_SUCCES, "Quit SDL_Mixer");
	SDL_Quit();
	ICE_Log(ICE_LOGTYPE_SUCCES, "Quit SDL");
	// PHYSFS
	PHYSFS_deinit();
	ICE_Log(ICE_LOGTYPE_FINISH, "Core Quit");
	ICE_Log_Line();

#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif

	return 0;
}
