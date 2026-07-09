/*
 * CreatureAttackData.cpp
 *
 *  Created on: Sep 28, 2010
 *      Author: dannuic
 */

#include "CreatureAttackData.h"
#include "server/zone/objects/creature/commands/CombatQueueCommand.h"
#include "server/zone/objects/creature/commands/effect/CommandEffect.h"

CreatureAttackData::CreatureAttackData(const UnicodeString& dataString, const CombatQueueCommand* base, uint64 target) {
	targetID = target;
	baseCommand = base;
	fillFromBase();

	StringTokenizer data(dataString.toString());
	data.setDelimeter(";");

	while (data.hasMoreTokens()) {
		String varString;
		data.getStringToken(varString);

		int pos = varString.indexOf("=");

		if (pos == -1)
			continue;

		String key = varString.subString(0,pos);
		String value = varString.subString(pos + 1, varString.length());

		setVariable(key, value);
	}
}

CreatureAttackData::CreatureAttackData(const CreatureAttackData& data) {
	baseCommand = data.baseCommand;
	targetID = data.targetID;

	damageMultiplier = data.damageMultiplier;
	healthDamageMultiplier = data.healthDamageMultiplier;
	actionDamageMultiplier = data.actionDamageMultiplier;
	mindDamageMultiplier = data.mindDamageMultiplier;
	minDamage = data.minDamage;
	maxDamage = data.maxDamage;
	damageType = data.damageType;
	accuracyBonus = data.accuracyBonus;
	speedMultiplier = data.speedMultiplier;
	poolsToDamage = data.poolsToDamage;
	frsLightMinDamageModifier = data.frsLightMinDamageModifier;
	frsLightMaxDamageModifier = data.frsLightMaxDamageModifier;
	frsDarkMinDamageModifier = data.frsDarkMinDamageModifier;
	frsDarkMaxDamageModifier = data.frsDarkMaxDamageModifier;

	healthCostMultiplier = data.healthCostMultiplier;
	actionCostMultiplier = data.actionCostMultiplier;
	mindCostMultiplier = data.mindCostMultiplier;
	forceCostMultiplier = data.forceCostMultiplier;

	stateEffects = data.stateEffects;
	dotEffects = data.dotEffects;

	range = data.range;
	coneAngle = data.coneAngle;
	coneRange = data.coneRange;
	areaRange = data.areaRange;

	splashDamage = data.splashDamage;
	hitIncapTarget = data.hitIncapTarget;

	forceAttack = data.forceAttack;
	trails = data.trails;

	combatSpam = data.combatSpam;

	stateAccuracyBonus = data.stateAccuracyBonus;
}

void CreatureAttackData::fillFromBase() {
	damageMultiplier = baseCommand->getDamageMultiplier();
	minDamage = baseCommand->getMinDamage();
	maxDamage = baseCommand->getMaxDamage();
	damageType = baseCommand->getDamageType();
	accuracyBonus = baseCommand->getAccuracyBonus();
	speedMultiplier = baseCommand->getSpeedMultiplier();
	healthCostMultiplier = baseCommand->getHealthCostMultiplier();
	actionCostMultiplier = baseCommand->getActionCostMultiplier();
	mindCostMultiplier = baseCommand->getMindCostMultiplier();
	forceCostMultiplier = baseCommand->getForceCostMultiplier();
	poolsToDamage = baseCommand->getPoolsToDamage();
	stateEffects = baseCommand->getStateEffects();
	dotEffects = baseCommand->getDotEffects();
	coneAngle = baseCommand->getConeAngle();
	coneRange = baseCommand->getConeRange();
	range = baseCommand->getRange();
	areaRange = baseCommand->getAreaRange();
	forceAttack = baseCommand->isForceAttack();
	trails = baseCommand->getTrails();
	combatSpam = baseCommand->getCombatSpam();
	splashDamage = baseCommand->isSplashDamage();
	frsLightMinDamageModifier = baseCommand->getFrsLightMinDamageModifier();
	frsLightMaxDamageModifier = baseCommand->getFrsLightMaxDamageModifier();
	frsDarkMinDamageModifier = baseCommand->getFrsDarkMinDamageModifier();
	frsDarkMaxDamageModifier = baseCommand->getFrsDarkMaxDamageModifier();

	stateAccuracyBonus = 0;

	healthDamageMultiplier = 1.f;
	actionDamageMultiplier = 1.f;
	mindDamageMultiplier = 1.f;

	hitIncapTarget = false;
}

void CreatureAttackData::setVariable(const String& var, const String& val) {
	uint32 crc = var.hashCode();
	switch(crc) {
	case 0x480C4BA4: // STRING_HASHCODE("minDamage"):
		minDamage = Float::valueOf(val);
		break;
	case 0xDDC00C87: // STRING_HASHCODE("maxDamage"):
		maxDamage = Float::valueOf(val);
		break;
	case 0x6980E997: // STRING_HASHCODE("damageType"):
		damageType = Integer::valueOf(val);
		break;
	case 0xA82FB287: // STRING_HASHCODE("damageMultiplier"):
		damageMultiplier = Float::valueOf(val);
		break;
	case 0xC60F1652: // STRING_HASHCODE("healthDamageMultiplier"):
		healthDamageMultiplier = Float::valueOf(val);
		break;
	case 0x77139783: // STRING_HASHCODE("actionDamageMultiplier"):
		actionDamageMultiplier = Float::valueOf(val);
		break;
	case 0xD7D06F99: // STRING_HASHCODE("mindDamageMultiplier"):
		mindDamageMultiplier = Float::valueOf(val);
		break;
	case 0xC33D0A1B: // String("accuracyBonus").hashcode()
		accuracyBonus = Integer::valueOf(val);
		break;
	case 0x7CA69F2E: // STRING_HASHCODE("speedMultiplier")
		speedMultiplier = Float::valueOf(val);
		break;
	case 0x3A1C0159: // STRING_HASHCODE("healthCostMultiplier")
		healthCostMultiplier = Float::valueOf(val);
		break;
	case 0x5FFD87F5: // STRING_HASHCODE("actionCostMultiplier")
		actionCostMultiplier = Float::valueOf(val);
		break;
	case 0xDF28A3E4: // STRING_HASHCODE("mindCostMultiplier")
		mindCostMultiplier = Float::valueOf(val);
		break;
	case 0xA3CB47C4: // STRING_HASHCODE("forceCostMultiplier")
		forceCostMultiplier = Float::valueOf(val);
		break;
	case 0xBF4C6ADB: // STRING_HASHCODE("poolsToDamage")
		poolsToDamage = Integer::valueOf(val);
		break;
	case 0xD2C29953: // STRING_HASHCODE("coneAngle")
		coneAngle = Integer::valueOf(val);
		break;
	case 0xE17D7C71: // STRING_HASHCODE("range")
		range = Integer::valueOf(val);
		break;
	case 0xFEC2FA79: // STRING_HASHCODE("areaRange")
		areaRange = Integer::valueOf(val);
		break;
	case STRING_HASHCODE("forceAttack"):
		forceAttack = (bool)Integer::valueOf(val);
		break;
	case 0x550ED3F5: // STRING_HASHCODE("trails")
		trails = Integer::valueOf(val);
		break;
	case 0xFAFA1475: // STRING_HASHCODE("combatSpam")
		combatSpam = val;
		break;
	case 0x97F6A373: // STRING_HASHCODE("stateAccuracyBonus")
		stateAccuracyBonus = Integer::valueOf(val);
		break;
	case 0xBD39E628: // STRING_HASHCODE("hitIncapTarget")
		hitIncapTarget = (bool)Integer::valueOf(val);
		break;
	default:
		break;
	}
}

const String& CreatureAttackData::getCommandName() const {
	return baseCommand->getQueueCommandName();
}

uint32 CreatureAttackData::getCommandCRC() const {
	return baseCommand->getNameCRC();
}

bool CreatureAttackData::changesDefenderPosture() const {
	if (stateEffects == nullptr)
		return false;

	for (int i = 0; i < stateEffects->size(); i++) {
		switch (stateEffects->get(i).getEffectType()) {
		case CommandEffect::KNOCKDOWN:
		case CommandEffect::POSTUREUP:
		case CommandEffect::POSTUREDOWN:
			return true;
		}
	}

	return false;
}

bool CreatureAttackData::changesAttackerPosture() const {
	if (stateEffects == nullptr)
		return false;

	for (int i = 0; i < stateEffects->size(); i++) {
		switch (stateEffects->get(i).getEffectType()) {
		case CommandEffect::ATTACKER_FORCE_STAND:
		case CommandEffect::ATTACKER_FORCE_CROUCH:
		case CommandEffect::ATTACKER_FORCE_PRONE:
			return true;
		}
	}

	return false;
}

float CreatureAttackData::getActionDamageMultiplier() const {
	return actionDamageMultiplier;
}

void CreatureAttackData::setActionDamageMultiplier(float actionDamageMultiplier) {
	this->actionDamageMultiplier = actionDamageMultiplier;
}

float CreatureAttackData::getHealthDamageMultiplier() const {
	return healthDamageMultiplier;
}

void CreatureAttackData::setHealthDamageMultiplier(float healthDamageMultiplier) {
	this->healthDamageMultiplier = healthDamageMultiplier;
}

float CreatureAttackData::getMindDamageMultiplier() const {
	return mindDamageMultiplier;
}

void CreatureAttackData::setMindDamageMultiplier(float mindDamageMultiplier) {
	this->mindDamageMultiplier = mindDamageMultiplier;
}

const CombatQueueCommand* CreatureAttackData::getCommand() const {
	return baseCommand;
}

float CreatureAttackData::getMinDamage() const {
	return minDamage;
}

float CreatureAttackData::getMaxDamage() const {
	return maxDamage;
}

int CreatureAttackData::getDamageType() const {
	return damageType;
}

int CreatureAttackData::getAccuracyBonus() const {
	return accuracyBonus;
}

float CreatureAttackData::getActionCostMultiplier() const {
	return actionCostMultiplier;
}

void CreatureAttackData::setSplashDamage(bool b) {
	splashDamage = b;
}

bool CreatureAttackData::isSplashDamage() const {
	return splashDamage;
}

bool CreatureAttackData::getHitIncapTarget() const {
	return hitIncapTarget;
}

int CreatureAttackData::getAreaRange() const {
	return areaRange;
}

int CreatureAttackData::getConeAngle() const {
	return coneAngle;
}

float CreatureAttackData::getDamageMultiplier() const {
	return damageMultiplier;
}

float CreatureAttackData::getForceCostMultiplier() const {
	return forceCostMultiplier;
}

float CreatureAttackData::getHealthCostMultiplier() const {
	return healthCostMultiplier;
}

float CreatureAttackData::getMindCostMultiplier() const {
	return mindCostMultiplier;
}

int CreatureAttackData::getPoolsToDamage() const {
	return poolsToDamage;
}

int CreatureAttackData::getConeRange() const {
	return coneRange;
}

int CreatureAttackData::getRange() const {
	return range;
}

float CreatureAttackData::getSpeedMultiplier() const {
	return speedMultiplier;
}

const VectorMap<uint8, StateEffect>* CreatureAttackData::getStateEffects() const {
	return stateEffects;
}

const Vector<DotEffect>* CreatureAttackData::getDotEffects() const {
	return dotEffects;
}

bool CreatureAttackData::isForceAttack() const {
	return forceAttack;
}

float CreatureAttackData::getFrsLightMinDamageModifier() const {
	return frsLightMinDamageModifier;
}

float CreatureAttackData::getFrsLightMaxDamageModifier() const {
	return frsLightMaxDamageModifier;
}

float CreatureAttackData::getFrsDarkMinDamageModifier() const {
	return frsDarkMinDamageModifier;
}

float CreatureAttackData::getFrsDarkMaxDamageModifier() const {
	return frsDarkMaxDamageModifier;
}

void CreatureAttackData::setForceAttack(bool forceAttack) {
	this->forceAttack = forceAttack;
}

uint8 CreatureAttackData::getTrails() const {
	return trails;
}

uint64 CreatureAttackData::getPrimaryTarget() const {
	return targetID;
}

void CreatureAttackData::setTrails(uint8 trails) {
	this->trails = trails;
}

const String& CreatureAttackData::getCombatSpam() const {
	return combatSpam;
}

void CreatureAttackData::setCombatSpam(const String& spam) {
	this->combatSpam = spam;
}

bool CreatureAttackData::isStateOnlyAttack() const {
	return poolsToDamage == 0;
}

int CreatureAttackData::getStateAccuracyBonus() const {
	return stateAccuracyBonus;
}

void CreatureAttackData::setStateAccuracyBonus(int stateAccuracyBonus) {
	this->stateAccuracyBonus = stateAccuracyBonus;
}