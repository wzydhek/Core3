#include "TangibleObjectDeltaMessage6.h"

TangibleObjectDeltaMessage6::TangibleObjectDeltaMessage6(TangibleObject* ta, uint32 objType) : DeltaMessage(ta->getObjectID(), objType, 6) {
	tano = ta;
}