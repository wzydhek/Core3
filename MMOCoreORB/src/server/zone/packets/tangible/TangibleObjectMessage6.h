/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"

class TangibleObjectMessage6 : public BaseLineMessage {
public:
	TangibleObjectMessage6(const TangibleObject* tano, uint32 objType = 0x54414E4F, uint16 opcnt = 0x02)
			: BaseLineMessage(tano, objType, 6, opcnt) {
		insertInt(0x76); // 0x3D in creos

		insertDefenders(tano);

		setSize();
	}

	void insertDefenders(const TangibleObject* tano) {
		const DeltaVector<ManagedReference<SceneObject*> >* defenderList = tano->getDefenderList();
		defenderList->insertToMessage(this);
	}

};
