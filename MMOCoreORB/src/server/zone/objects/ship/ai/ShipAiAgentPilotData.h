#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {
namespace ai {

class ShipAiAgentPilotData : public Object {
public:
	const static int DATA_SIZE = 16;

protected:
	String pilotName;
	String pilotType;
	int holdFire;
	float speedRotationFactorMin;
	float speedRotationFactorOptimal;
	float speedRotationFactorMax;
	float slideDamp;
	float engineSpeed;
	float engineAccel;
	float engineDecel;
	float engineYaw;
	float engineYawAccel;
	float enginePitch;
	float enginePitchAccel;
	float engineRoll;
	float engineRollAccel;

public:
	ShipAiAgentPilotData();

	void readObject(LuaObject* row);

	String getPilotName() const;

	String getPilotType() const;

	int getHoldFire() const;

	float getSpeedRotationFactorMin() const;

	float getSpeedRotationFactorOptimal() const;

	float getSpeedRotationFactorMax() const;

	float getSlideDamp() const;

	float getEngineSpeed() const;

	float getEngineAccel() const;

	float getEngineDecel() const;

	float getEngineYaw() const;

	float getEngineYawAccel() const;

	float getEnginePitch() const;

	float getEnginePitchAccel() const;

	float getEngineRoll() const;

	float getEngineRollAccel() const;
};

} // namespace ai
} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship::ai;
