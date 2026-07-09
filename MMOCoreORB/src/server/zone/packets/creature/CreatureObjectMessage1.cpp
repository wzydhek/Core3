#include "CreatureObjectMessage1.h"
#include "server/zone/objects/creature/variables/SkillList.h"

CreatureObjectMessage1::CreatureObjectMessage1(const CreatureObject* creo) : BaseLineMessage(creo, 0x4352454F, 1, 0x04) {
	insertInt(creo->getBankCredits());
	insertInt(creo->getCashCredits());

	// Base HAM
	const DeltaVector<int>* baseHam = creo->getBaseHAM();
	baseHam->insertToMessage(this);

	const SkillList* skillList = creo->getSkillList();
	skillList->insertToMessage(this);

	setSize();

	setCompression(true);
}