/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

class ManufactureSchematicObjectMessage6 : public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage6(uint64 oid, uint32 schematicCRC, bool activeCraft);
};
