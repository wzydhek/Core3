/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class TangibleObjectMessage8 : public BaseLineMessage {
public:
	TangibleObjectMessage8(const TangibleObject* tano)
			: BaseLineMessage(tano, 0x54414E4F, 8, 0x00) {

		setSize();
	}

};
