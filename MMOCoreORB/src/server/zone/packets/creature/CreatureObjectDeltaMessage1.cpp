#include "CreatureObjectDeltaMessage1.h"

CreatureObjectDeltaMessage1::CreatureObjectDeltaMessage1(CreatureObjectImplementation* cr) : DeltaMessage(cr->getObjectID(), 0x4352454F, 1) {
	creo = cr;
}

void CreatureObjectDeltaMessage1::updateBankCredits() {
	startUpdate(0x00);
	insertInt(creo->getBankCredits());
}

void CreatureObjectDeltaMessage1::updateCashCredits() {
	startUpdate(0x01);
	insertInt(creo->getCashCredits());
}