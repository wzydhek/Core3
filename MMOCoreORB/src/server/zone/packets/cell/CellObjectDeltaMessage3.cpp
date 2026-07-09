#include "CellObjectDeltaMessage3.h"

CellObjectDeltaMessage3::CellObjectDeltaMessage3(CellObject* co) : DeltaMessage(co->getObjectID(), 0x53434C54, 3) {
	cell = co;
}

void CellObjectDeltaMessage3::updateCellNumber(int cellNumber) {
	addIntUpdate(5, cellNumber);
}