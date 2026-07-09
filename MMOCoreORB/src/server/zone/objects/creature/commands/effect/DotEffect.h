/*
 * DotEffect.h
 *
 *  Created on: Jan 19, 2012
 *      Author: da
 */

#pragma once

#include "engine/engine.h"

class DotEffect : public Object {
protected:
	uint32 dotType;
	Vector<String> defenderStateDefenseModifiers;
	uint8 dotPool;
	bool dotDamageofHit;
	uint32 dotDuration;
	uint32 dotStrength;
	int dotPotency;
	uint32 dotChance;
	float primaryPercent;
	float secondaryPercent;

public:
	DotEffect();

	DotEffect(LuaObject& dot);

	DotEffect(const DotEffect& effect);

	virtual ~DotEffect();

	DotEffect& operator=(const DotEffect& effect);

	inline int compareTo(const DotEffect& effect);

	void loadDot(LuaObject& dot);

	const Vector<String>& getDefenderStateDefenseModifiers() const;

	uint32 getDotDuration() const;

	uint8 getDotPool() const;

	int getDotPotency() const;

	uint32 getDotStrength() const;

	uint32 getDotType() const;

	bool isDotDamageofHit() const;

	void setDefenderStateDefenseModifiers(const Vector<String>& defenderStateDefenseModifiers);

	void setDotDamageofHit(bool dotDamageofHit);

	void setDotDuration(uint32 dotDuration);

	void setDotPool(uint8 dotPool);

	void setDotPotency(int dotPotency);

	void setDotStrength(uint32 dotStrength);

	void setDotType(uint32 dotType);

	uint32 getDotChance() const;

	void setDotChance(uint32 dotChance);

	float getPrimaryPercent() const;

	float getSecondaryPercent() const;

};
