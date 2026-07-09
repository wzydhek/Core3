#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

class ShipMissileData : public Object {
public:
	enum PlayerMissileType : int {
		CONCUSSION_MK1 = 0,
		CONCUSSION_MK2 = 1,
		CONCUSSION_MK3 = 2,
		IMAGEREC_MK1 = 3,
		IMAGEREC_MK2 = 4,
		PROTON_MK1 = 5,
		PROTON_MK2 = 6,
		PROTON_MK3 = 7,
		PROTON_MK4 = 8,
		SEISMIC_MK1 = 9,
		SEISMIC_MK2 = 10,
		SEISMIC_MK3 = 11,
		SPACEBOMB_MK1 = 12,
		SPACEBOMB_MK2 = 13
	};

	enum AiMissileType : int {
		AI_PROTON_TIER1 = 16,
		AI_PROTON_TIER2 = 17,
		AI_PROTON_TIER3 = 18,
		AI_PROTON_TIER4 = 19,
		AI_PROTON_TIER5 = 20,
	};

	static int getLauncherAmmoType(const String& dataName);

	static int getMissileAmmoType(uint32 objectCRC);

protected:
	int missileType;

	String dataName;

	float minTime;
	float maxTime;
	float serverSpeed;
	float clientSpeed;
	float countermeasureFactor;
	float targetAquisitionTime;
	float targetAquisitionAngle;

	String appearance;
	String trail;
	String fireEffect;
	String hitEffect;
	String counterEffect;

	int counterDifficulty;

public:
	ShipMissileData();

	void readObject(DataTableRow* row);

	// set
	void setMissileType(int value);

	void setDataName(const String& value);

	void setMinTime(int value);

	void setMaxTime(int value);

	void setServerSpeed(int value);

	void setClientSpeed(int value);

	void setCountermeasureFactor(float value);

	void setTargetAquisitionTime(int value);

	void setTargetAquisitionAngle(int value);

	void setAppearance(const String& value);

	void setTrail(const String& value);

	void setFireEffect(const String& value);

	void setHitEffect(const String& value);

	void setCounterEffect(const String& value);

	void setCounterDifficulty(int value);

	// get
	int getMissileType() const;

	const String& getDataName() const;

	float getMinTime() const;

	float getMaxTime() const;

	float getServerSpeed() const;

	float getClientSpeed() const;

	float getCountermeasureFactor() const;

	float getTargetAquisitionTime() const;

	float getTargetAquisitionAngle() const;

	const String& getAppearance() const;

	const String& getTrail() const;

	const String& getFireEffect() const;

	const String& getHitEffect() const;

	const String& getCounterEffect() const;

	int getCounterDifficulty() const;
};
