/*
 * StateEffect.h
 *
 *  Created on: Jan 16, 2012
 *      Author: da
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace effect {

class StateEffect : public Object {
protected:
	uint8 effectType;
	Vector<String> defenderExclusionTimers;
	Vector<String> defenderStateDefenseModifiers;
	Vector<String> defenderJediStateDefenseModifiers;
	uint32 stateChance;
	uint32 stateStrength;
	uint32 stateLength;

public:
	StateEffect();

	StateEffect(LuaObject state);

	StateEffect(const StateEffect& effect);

	StateEffect& operator=(const StateEffect& effect);

	int compareTo(const StateEffect& effect) const;

	virtual ~StateEffect();

	void loadState(LuaObject state);

	const Vector<String>& getDefenderExclusionTimers() const;

	const Vector<String>& getDefenderJediStateDefenseModifiers() const;

	const Vector<String>& getDefenderStateDefenseModifiers() const;

	uint8 getEffectType() const;

	uint32 getStateChance() const;

	uint32 getStateLength() const;

	uint32 getStateStrength() const;

	void setDefenderExclusionTimers(const Vector<String>& defenderExclusionTimers);

	void setDefenderJediStateDefenseModifiers(const Vector<String>& defenderJediStateDefenseModifiers);

	void setDefenderStateDefenseModifiers(const Vector<String>& defenderStateDefenseModifiers);

	void setEffectType(uint8 effectType);

	void setStateChance(uint32 stateChance);

	void setStateLength(uint32 stateLength);

	void setStateStrength(uint32 stateStrength);
};

} // namespace effect
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::effect;
