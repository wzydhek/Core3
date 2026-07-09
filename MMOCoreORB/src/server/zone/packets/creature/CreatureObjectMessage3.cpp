#include "CreatureObjectMessage3.h"

CreatureObjectMessage3::CreatureObjectMessage3(CreatureObject* creo) : TangibleObjectMessage3(creo, 0x4352454F, 0x12) {
	insertByte(creo->getPosture());
	insertByte(creo->getFactionRank()); // faction rank

	insertLong(creo->getCreatureLinkID()); // creature link id/ mount

	insertFloat(creo->getHeight());
	insertInt((int)creo->getShockWounds()); // BF

	insertLong(creo->getStateBitmask());

	const DeltaVector<int>* wounds = creo->getWounds();
	wounds->insertToMessage(this);

	setSize();
}