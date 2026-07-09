/*
 * Badges.h
 *
 *  Created on: 02/02/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/managers/player/BadgeList.h"
#include "Badge.h"

class Badges : public Serializable, public ReadWriteLock {
	uint32 badgeBitmask[5];
	uint8 badgeTypeCounts[6];
	uint8 badgeTotal;
public:
	Badges();

	Badges(const Badges& badges);

	Badges& operator=(const Badges& badges);

	void addSerializableVariables();

public:

	friend void to_json(nlohmann::json& j, const Badges& b);

	void setBadge(const uint32 badgeid);

	void setBadge(const Badge* badge);

	void unsetBadge(const uint32 badgeid);

	void unsetBadge(const Badge* badge);

	bool hasBadge(int badgeindex) const;

	void setBitmask(int index, uint32 bitmask);

	uint32 getBitmask(int index) const;

	void setTypeCount(uint8 index, uint8 value);

	uint8 getTypeCount(uint8 type) const;

	uint8 getNumBadges() const;

	void setNumBadges(uint8 value);
};
