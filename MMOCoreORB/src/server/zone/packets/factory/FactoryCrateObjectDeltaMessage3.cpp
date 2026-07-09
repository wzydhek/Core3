#include "FactoryCrateObjectDeltaMessage3.h"

FactoryCrateObjectDeltaMessage3::FactoryCrateObjectDeltaMessage3(FactoryCrate* ta, uint32 objType) : DeltaMessage(ta->getObjectID(), objType, 3) {
	tano = ta;
}

void FactoryCrateObjectDeltaMessage3::setQuantity(int quantity) {
	addIntUpdate(7, quantity);
}