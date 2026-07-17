/*
 * LairTemplate.h
 *
 *  Created on: 29/08/2011
 *      Author: TheAnswer
 */

#pragma once

#include "engine/lua/LuaObject.h"
#include "templates/faction/Factions.h"

namespace templates {
namespace mobile {

class LairTemplate : public Object {
public:
	enum MobType {CREATURE, NPC};
	enum BuildingType {LAIR, THEATER, NONE};

protected:
	VectorMap<String, int> mobiles; // mobile template, weighting
	Vector<String> weightedMobiles;
	VectorMap<String, int> bossMobiles; // mobile template, number to spawn
	int spawnLimit;

	VectorMap<uint32, Reference<Vector<String>*> > buildings;

	String missionBuilding;
	String name;

	unsigned int faction;

	MobType mobType;
	BuildingType buildingType;

public:
	enum { VERYEASY = 0, EASY, MEDIUM, HARD, VERYHARD};

	LairTemplate(const String& templateName);

	virtual ~LairTemplate();

	String getBuilding(uint32 difficulty) const;

	String getMissionBuilding(uint32 difficulty) const;

	const Vector<String>* getBuildings(int difficulty) const;

	void readObject(LuaObject* templateData);

	int getSpawnLimit() const;

	const VectorMap<String, int>* getMobiles() const;

	const Vector<String>* getWeightedMobiles() const;

	const VectorMap<String, int>* getBossMobiles() const;

	bool hasBossMobs() const;

	bool isLairTemplate();

	const String& getName() const;

	unsigned int getFaction() const;

	MobType getMobType() const;

	BuildingType getBuildingType() const;
};

} // namespace mobile
} // namespace templates

using namespace templates::mobile;
