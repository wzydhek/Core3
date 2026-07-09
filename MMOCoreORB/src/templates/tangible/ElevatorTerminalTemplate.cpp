#include "ElevatorTerminalTemplate.h"

ElevatorTerminalTemplate::ElevatorTerminalTemplate() {
	movementType = UPONLY;
}

ElevatorTerminalTemplate::~ElevatorTerminalTemplate() {
}

void ElevatorTerminalTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	movementType = templateData->getByteField("movementType");
}

byte ElevatorTerminalTemplate::getMovementType() {
	return movementType;
}

bool ElevatorTerminalTemplate::isMovingUp() {
	return (movementType == UPONLY || movementType == UPANDDOWN);
}

bool ElevatorTerminalTemplate::isMovingDown() {
	return (movementType == DOWNONLY || movementType == UPANDDOWN);
}