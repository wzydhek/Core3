/*
 * GuildStructurePermissionsTask.h
 *
 *	Created: 10/3/2023
 *	By: Hakry
 */

#pragma once

#include "server/zone/objects/guild/GuildObject.h"
#include "server/zone/objects/building/BuildingObject.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

class GuildStructurePermissionsTask : public Task {
	ManagedWeakReference<BuildingObject*> weakBuilding;
	WeakReference<GuildObject*> weakGuild;

public:
	GuildStructurePermissionsTask(BuildingObject* buildingObj, GuildObject* guildObj);

	void run();
};

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;
