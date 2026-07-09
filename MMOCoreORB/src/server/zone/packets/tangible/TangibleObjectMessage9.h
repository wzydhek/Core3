/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class TangibleObjectMessage9 : public BaseLineMessage {
public:
	TangibleObjectMessage9(const TangibleObject* tano);

};
