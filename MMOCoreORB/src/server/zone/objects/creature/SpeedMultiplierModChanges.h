/*
 * SpeedMultiplierModChanges.h
 *
 *  Created on: 24/11/2010
 *      Author: victor
 */

#pragma once

#include "system/util/ArrayList.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {

class SpeedModChange {
	float newSpeed;
	Time timeStamp;

public:
	SpeedModChange();

	SpeedModChange(float speed);

	SpeedModChange(float speed, Time& tm);

	SpeedModChange(const SpeedModChange& a);

	SpeedModChange& operator=(const SpeedModChange& a);

	float getNewSpeed() const;

	const Time& getTimeStamp() const;

	bool parseFromBinaryStream(ObjectInputStream* stream);

	bool toBinaryStream(ObjectOutputStream* stream);

	friend void to_json(nlohmann::json& j, const SpeedModChange& v);
};

class SpeedMultiplierModChanges : public ArrayList<SpeedModChange> {

};

void to_json(nlohmann::json& j, const SpeedModChange& v);

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;
