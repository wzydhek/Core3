/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

class ManufactureSchematicObjectMessage3 : public BaseLineMessage, public Logger {
public:
	ManufactureSchematicObjectMessage3(uint64 oid, float complexity, String playerName);

	ManufactureSchematicObjectMessage3(ManufactureSchematic* manufactureSchematic, String playerName);
};
