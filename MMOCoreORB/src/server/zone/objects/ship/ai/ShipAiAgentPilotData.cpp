#include "ShipAiAgentPilotData.h"

ShipAiAgentPilotData::ShipAiAgentPilotData() : Object() {
	holdFire = 0;
	speedRotationFactorMin = 0.f;
	speedRotationFactorOptimal = 0.f;
	speedRotationFactorMax = 0.f;
	slideDamp = 0.f;
	engineSpeed = 0.f;
	engineAccel = 0.f;
	engineDecel = 0.f;
	engineYaw = 0.f;
	engineYawAccel = 0.f;
	enginePitch = 0.f;
	enginePitchAccel = 0.f;
	engineRoll = 0.f;
	engineRollAccel = 0.f;
}

void ShipAiAgentPilotData::readObject(LuaObject* row) {
	if (row == nullptr || row->getTableSize() < DATA_SIZE) {
		return;
	}

	pilotName = row->getStringAt(1);
	pilotType = row->getStringAt(2);
	holdFire = row->getIntAt(3);
	speedRotationFactorMin = row->getFloatAt(4);
	speedRotationFactorOptimal = row->getFloatAt(5);
	speedRotationFactorMax = row->getFloatAt(6);
	slideDamp = row->getFloatAt(7);
	engineSpeed = row->getFloatAt(8);
	engineAccel = row->getFloatAt(9);
	engineDecel = row->getFloatAt(10);
	engineYaw = row->getFloatAt(11) * Math::DEG2RAD;
	engineYawAccel = row->getFloatAt(12) * Math::DEG2RAD;
	enginePitch = row->getFloatAt(13) * Math::DEG2RAD;
	enginePitchAccel = row->getFloatAt(14) * Math::DEG2RAD;
	engineRoll = row->getFloatAt(15) * Math::DEG2RAD;
	engineRollAccel = row->getFloatAt(16) * Math::DEG2RAD;
}

String ShipAiAgentPilotData::getPilotName() const {
	return pilotName;
}

String ShipAiAgentPilotData::getPilotType() const {
	return pilotType;
}

int ShipAiAgentPilotData::getHoldFire() const {
	return holdFire;
}

float ShipAiAgentPilotData::getSpeedRotationFactorMin() const {
	return speedRotationFactorMin;
}

float ShipAiAgentPilotData::getSpeedRotationFactorOptimal() const {
	return speedRotationFactorOptimal;
}

float ShipAiAgentPilotData::getSpeedRotationFactorMax() const {
	return speedRotationFactorMax;
}

float ShipAiAgentPilotData::getSlideDamp() const {
	return slideDamp;
}

float ShipAiAgentPilotData::getEngineSpeed() const {
	return engineSpeed;
}

float ShipAiAgentPilotData::getEngineAccel() const {
	return engineAccel;
}

float ShipAiAgentPilotData::getEngineDecel() const {
	return engineDecel;
}

float ShipAiAgentPilotData::getEngineYaw() const {
	return engineYaw;
}

float ShipAiAgentPilotData::getEngineYawAccel() const {
	return engineYawAccel;
}

float ShipAiAgentPilotData::getEnginePitch() const {
	return enginePitch;
}

float ShipAiAgentPilotData::getEnginePitchAccel() const {
	return enginePitchAccel;
}

float ShipAiAgentPilotData::getEngineRoll() const {
	return engineRoll;
}

float ShipAiAgentPilotData::getEngineRollAccel() const {
	return engineRollAccel;
}