/*
 * CampStructureObjectTemplate.cpp
 *
 *  Created on: Jan 2, 2012
 *      Author: Kyle
 */


#include "CampStructureTemplate.h"

CampStructureTemplate::CampStructureTemplate() : experience(0), duration(0), radius(0), aggroMod(0), skillRequired(0), healthWoundRegenRate(0), actionWoundRegenRate(0), mindWoundRegenRate(0) {
}

CampStructureTemplate::~CampStructureTemplate() {
}

void CampStructureTemplate::readObject(LuaObject* templateData) {
	SharedBuildingObjectTemplate::readObject(templateData);

	duration = templateData->getIntField("duration");
	radius = templateData->getFloatField("radius");
	experience = templateData->getIntField("experience");
	aggroMod = templateData->getIntField("aggroMod");
	skillRequired = templateData->getIntField("skillRequired");

	healthWoundRegenRate = templateData->getIntField("healthWoundRegenRate");
	actionWoundRegenRate = templateData->getIntField("actionWoundRegenRate");
	mindWoundRegenRate = templateData->getIntField("mindWoundRegenRate");
}

bool CampStructureTemplate::isCampStructureTemplate() {
	return true;
}

int CampStructureTemplate::getDuration() const {
	return duration;
}

int CampStructureTemplate::getExperience() const {
	return experience;
}

int CampStructureTemplate::getRadius() const {
	return radius;
}

int CampStructureTemplate::getAggroMod() const {
	return aggroMod;
}

int CampStructureTemplate::getSkillRequired() const {
	return skillRequired;
}

int CampStructureTemplate::getHealthWoundRegenRate() {
	return healthWoundRegenRate;
}

int CampStructureTemplate::getActionWoundRegenRate() {
	return actionWoundRegenRate;
}

int CampStructureTemplate::getMindWoundRegenRate() {
	return mindWoundRegenRate;
}