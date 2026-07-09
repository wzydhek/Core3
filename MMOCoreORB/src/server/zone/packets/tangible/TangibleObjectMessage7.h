/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class TangibleObjectMessage7 : public BaseLineMessage {
public:
	TangibleObjectMessage7(const TangibleObject* tano);

};
