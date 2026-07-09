#include "DotEffect.h"

DotEffect::DotEffect() : Object() {
	dotType = 0;
	dotPool = 0;
	dotDamageofHit = 0;
	dotDuration = 0;
	dotStrength = 0;
	dotPotency = 0;
	dotChance = 0;
	primaryPercent = 100;
	secondaryPercent = 0;
}

DotEffect::DotEffect(LuaObject& dot) : Object() {
	loadDot(dot);
}

DotEffect::DotEffect(const DotEffect& effect) : Object() {
	dotType = effect.dotType;
	defenderStateDefenseModifiers = effect.defenderStateDefenseModifiers;
	dotPool = effect.dotPool;
	dotDamageofHit = effect.dotDamageofHit;
	dotDuration = effect.dotDuration;
	dotStrength = effect.dotStrength;
	dotPotency = effect.dotPotency;
	dotChance = effect.dotChance;
	primaryPercent = effect.primaryPercent;
	secondaryPercent = effect.secondaryPercent;
}

DotEffect::~DotEffect() {
}

DotEffect& DotEffect::operator=(const DotEffect& effect) {
	if (this == &effect)
		return *this;

	dotType = effect.dotType;
	defenderStateDefenseModifiers = effect.defenderStateDefenseModifiers;
	dotPool = effect.dotPool;
	dotDamageofHit = effect.dotDamageofHit;
	dotDuration = effect.dotDuration;
	dotStrength = effect.dotStrength;
	dotPotency = effect.dotPotency;
	dotChance = effect.dotChance;
	primaryPercent = effect.primaryPercent;
	secondaryPercent = effect.secondaryPercent;

	return *this;
}

int DotEffect::compareTo(const DotEffect& effect) {
	return 0;
}

void DotEffect::loadDot(LuaObject& dot) {
	dotType = dot.getIntField("dotType");
	dotPool = dot.getByteField("dotPool");
	LuaObject dohBool = dot.getObjectField("dotDamageofHit");
	lua_State* L = dohBool.getLuaState();
	dotDamageofHit = (bool)((lua_toboolean(L, -1)));
	dohBool.pop();
	dotDuration = dot.getIntField("dotDuration");
	dotStrength = dot.getIntField("dotStrength");
	dotPotency = dot.getIntField("dotPotency");
	dotChance = dot.getIntField("dotChance");
	primaryPercent = dot.getFloatField("primaryPercent");
	secondaryPercent = dot.getFloatField("secondaryPercent");

	LuaObject defMods = dot.getObjectField("defenderStateDefenseModifiers");
	for (int i = 1; i <= defMods.getTableSize(); ++i) {
		defenderStateDefenseModifiers.add(defMods.getStringAt(i));
	}

	defMods.pop();
}

const Vector<String>& DotEffect::getDefenderStateDefenseModifiers() const {
	return defenderStateDefenseModifiers;
}

uint32 DotEffect::getDotDuration() const {
	return dotDuration;
}

uint8 DotEffect::getDotPool() const {
	return dotPool;
}

int DotEffect::getDotPotency() const {
	return dotPotency;
}

uint32 DotEffect::getDotStrength() const {
	return dotStrength;
}

uint32 DotEffect::getDotType() const {
	return dotType;
}

bool DotEffect::isDotDamageofHit() const {
	return dotDamageofHit;
}

void DotEffect::setDefenderStateDefenseModifiers(const Vector<String>& defenderStateDefenseModifiers) {
	this->defenderStateDefenseModifiers = defenderStateDefenseModifiers;
}

void DotEffect::setDotDamageofHit(bool dotDamageofHit) {
	this->dotDamageofHit = dotDamageofHit;
}

void DotEffect::setDotDuration(uint32 dotDuration) {
	this->dotDuration = dotDuration;
}

void DotEffect::setDotPool(uint8 dotPool) {
	this->dotPool = dotPool;
}

void DotEffect::setDotPotency(int dotPotency) {
	this->dotPotency = dotPotency;
}

void DotEffect::setDotStrength(uint32 dotStrength) {
	this->dotStrength = dotStrength;
}

void DotEffect::setDotType(uint32 dotType) {
	this->dotType = dotType;
}

uint32 DotEffect::getDotChance() const {
	return dotChance;
}

void DotEffect::setDotChance(uint32 dotChance) {
	this->dotChance = dotChance;
}

float DotEffect::getPrimaryPercent() const {
	return primaryPercent;
}

float DotEffect::getSecondaryPercent() const {
	return secondaryPercent;
}