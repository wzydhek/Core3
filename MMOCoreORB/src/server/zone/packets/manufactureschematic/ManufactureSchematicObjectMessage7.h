/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class ManufactureSchematicObjectMessage7: public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage7(SceneObject* schematic);

};
