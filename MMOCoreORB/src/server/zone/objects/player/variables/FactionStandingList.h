/*
 * FactionStandingList.h
 *
 *  Created on: Mar 16, 2011
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

class FactionStandingList : public Serializable {
	SerializableString factionRank;
	int rebelPoints;
	int imperialPoints;
	SynchronizedVectorMap<String, float> factions;
	//int huttPoints; //Disabled

public:
	FactionStandingList();

	FactionStandingList(const FactionStandingList& f);

	FactionStandingList& operator=(const FactionStandingList& f);

	void addSerializableVariables();

	friend void to_json(nlohmann::json& j, const FactionStandingList& l);

	float get(const String& faction) const;

	int size() const;

	void put(const String& faction, float amount);

	float getFactionStanding(const String& faction) const;

	bool contains(const String& faction) const;

	bool isPvpFaction(const String& faction) const;

	const String& getFactionRank() const;

	void setRebelPoints(int amount);

	void setImperialPoints(int amount);

	void increaseRebelPoints(int amount);

	void decreaseRebelPoints(int amount);

	void increaseImperialPoints(int amount);

	void decreaseImperialPoints(int amount);

	void setFactionRank(const String& rank);

	int getImperialPoints() const;

	int getRebelPoints() const;

	int getHuttPoints() const;

	void insertToMessage(BaseMessage* message) const;
};
