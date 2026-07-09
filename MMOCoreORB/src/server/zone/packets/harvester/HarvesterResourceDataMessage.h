/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/object/ObjectControllerMessage.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/resource/ResourceSpawn.h"

class HarvesterResourceDataMessage : public ObjectControllerMessage {
public:
	HarvesterResourceDataMessage(CreatureObject* player, InstallationObject* hino, Zone* zone);

	void insertResourceList(Vector<ManagedReference<ResourceSpawn*>>* list, InstallationObject* hino);

};

/*

if (list == nullptr)
	System::out << "list was null!" << endl;
*/
