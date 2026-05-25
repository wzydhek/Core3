/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class TangibleObjectMessage7 : public BaseLineMessage {
public:
	TangibleObjectMessage7(const TangibleObject* tano)
			: BaseLineMessage(tano, 0x54414E4F, 7, 0x02) {
		insertLong(0);
		insertLong(0);

		setSize();
	}

};
