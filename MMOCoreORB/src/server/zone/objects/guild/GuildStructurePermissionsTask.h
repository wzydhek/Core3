/*
 * GuildStructurePermissionsTask.h
 *
 *	Created: 10/3/2023
 *	By: Hakry
 */

#pragma once

#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/objects/building/BuildingObject.h"

class GuildStructurePermissionsTask : public Task {
	ManagedWeakReference<BuildingObject*> weakBuilding;
	WeakReference<GuildObject*> weakGuild;

public:
	GuildStructurePermissionsTask(BuildingObject* buildingObj, GuildObject* guildObj);

	void run();
};
