﻿#ifndef DEF_ICE_ENTITYMANAGER_PRIVATE_H
#define DEF_ICE_ENTITYMANAGER_PRIVATE_H

#include "Entity_private.h"

struct ICE_EntityManager
{
	ICE_Bool		isFree;
	
	ICE_ID			entity_size;
	ICE_ID			entity_contain;
	ICE_Entity*		entity;

}; typedef struct ICE_EntityManager ICE_EntityManager;

#define ICE_DEFAULT_ENTITY_MNGR_SIZE 4

#endif