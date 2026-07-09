/*
 * Faction.h
 *
 *  Created on: Mar 17, 2011
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"

class Faction : public Object {
	String factionName;
	bool playerAllowed;
	SortedVector<String> enemies;
	SortedVector<String> allies;
	float adjustFactor;

public:

	Faction();

	Faction(const String& name);

	Faction(const Faction& f);

	Faction& operator=(const Faction& f);

	void parseEnemiesFromList(const String& list);

	void parseAlliesFromList(const String& list);

	const String& getFactionName() const;

	void setPlayerAllowed(bool allowed);

	void setAdjustFactor(float factor);

	const SortedVector<String>* getEnemies() const;

	const SortedVector<String>* getAllies() const;

	bool isPlayerAllowed() const;

	float getAdjustFactor() const;
};
