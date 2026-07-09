#include "TerminalSpawn.h"

TerminalSpawn::TerminalSpawn(String name, Vector3 loc, int cell, Quaternion rot) : Object() {
	templateName = name;
	cellID = cell;
	spawnLoc = loc;
	rotation = rot;
}

TerminalSpawn::~TerminalSpawn() {
}

String TerminalSpawn::getTemplateName() {
	return templateName;
}

int TerminalSpawn::getCellID() {
	return cellID;
}

Vector3* TerminalSpawn::getSpawnLoc() {
	return &spawnLoc;
}

Quaternion TerminalSpawn::getRotation() const {
	return rotation;
}