#include "TangibleObjectMessage6.h"

TangibleObjectMessage6::TangibleObjectMessage6(const TangibleObject* tano, uint32 objType, uint16 opcnt) : BaseLineMessage(tano, objType, 6, opcnt) {
	insertInt(0x76); // 0x3D in creos

	insertDefenders(tano);

	setSize();
}

void TangibleObjectMessage6::insertDefenders(const TangibleObject* tano) {
	const DeltaVector<ManagedReference<SceneObject*>>* defenderList = tano->getDefenderList();
	defenderList->insertToMessage(this);
}