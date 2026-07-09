#include "StateEffect.h"

StateEffect::StateEffect() : Object() {
	effectType = 0;
	stateChance = 0;
	stateStrength = 0;
	stateLength = 0;
}

StateEffect::StateEffect(LuaObject state) : Object() {
	loadState(state);
}

StateEffect::StateEffect(const StateEffect& effect) : Object() {
	effectType = effect.effectType;
	defenderExclusionTimers = effect.defenderExclusionTimers;
	defenderStateDefenseModifiers = effect.defenderStateDefenseModifiers;
	defenderJediStateDefenseModifiers = effect.defenderJediStateDefenseModifiers;
	stateChance = effect.stateChance;
	stateStrength = effect.stateStrength;
	stateLength = effect.stateLength;
}

StateEffect& StateEffect::operator=(const StateEffect& effect) {
	if (this == &effect)
		return *this;

	effectType = effect.effectType;
	defenderExclusionTimers = effect.defenderExclusionTimers;
	defenderStateDefenseModifiers = effect.defenderStateDefenseModifiers;
	defenderJediStateDefenseModifiers = effect.defenderJediStateDefenseModifiers;
	stateChance = effect.stateChance;
	stateStrength = effect.stateStrength;
	stateLength = effect.stateLength;

	return *this;
}

int StateEffect::compareTo(const StateEffect& effect) const {
	return 0;
}

StateEffect::~StateEffect() {
}

void StateEffect::loadState(LuaObject state) {
	effectType = state.getByteField("effectType");
	stateChance = state.getIntField("stateChance");
	stateStrength = state.getIntField("stateStrength");
	stateLength = state.getIntField("stateLength");

	LuaObject defTimers = state.getObjectField("defenderExclusionTimers");

	for (int i = 1; i <= defTimers.getTableSize(); ++i) {
		defenderExclusionTimers.add(defTimers.getStringAt(i));
	}

	defTimers.pop();

	LuaObject defMods = state.getObjectField("defenderStateDefenseModifiers");

	for (int i = 1; i <= defMods.getTableSize(); ++i) {
		defenderStateDefenseModifiers.add(defMods.getStringAt(i));
	}

	defMods.pop();

	LuaObject jediMods = state.getObjectField("defenderJediStateDefenseModifiers");

	for (int i = 1; i <= jediMods.getTableSize(); ++i) {
		defenderJediStateDefenseModifiers.add(jediMods.getStringAt(i));
	}

	jediMods.pop();
}

const Vector<String>& StateEffect::getDefenderExclusionTimers() const {
	return defenderExclusionTimers;
}

const Vector<String>& StateEffect::getDefenderJediStateDefenseModifiers() const {
	return defenderJediStateDefenseModifiers;
}

const Vector<String>& StateEffect::getDefenderStateDefenseModifiers() const {
	return defenderStateDefenseModifiers;
}

uint8 StateEffect::getEffectType() const {
	return effectType;
}

uint32 StateEffect::getStateChance() const {
	return stateChance;
}

uint32 StateEffect::getStateLength() const {
	return stateLength;
}

uint32 StateEffect::getStateStrength() const {
	return stateStrength;
}

void StateEffect::setDefenderExclusionTimers(const Vector<String>& defenderExclusionTimers) {
	this->defenderExclusionTimers = defenderExclusionTimers;
}

void StateEffect::setDefenderJediStateDefenseModifiers(const Vector<String>& defenderJediStateDefenseModifiers) {
	this->defenderJediStateDefenseModifiers = defenderJediStateDefenseModifiers;
}

void StateEffect::setDefenderStateDefenseModifiers(const Vector<String>& defenderStateDefenseModifiers) {
	this->defenderStateDefenseModifiers = defenderStateDefenseModifiers;
}

void StateEffect::setEffectType(uint8 effectType) {
	this->effectType = effectType;
}

void StateEffect::setStateChance(uint32 stateChance) {
	this->stateChance = stateChance;
}

void StateEffect::setStateLength(uint32 stateLength) {
	this->stateLength = stateLength;
}

void StateEffect::setStateStrength(uint32 stateStrength) {
	this->stateStrength = stateStrength;
}