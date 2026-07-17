/*
 * EntertainingData.h
 *
 *  Created on: 20/09/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class EntertainingData : public Serializable {
	int duration;
	int strength;
	int timeStarted;
public:
	EntertainingData();

	EntertainingData(const EntertainingData& d);

	EntertainingData& operator=(const EntertainingData& d);

	void addSerializableVariables();

	int getDuration();

	int getStrength();

	int getTimeStarted();

	void setStrength(int str);

	void incrementStrength(int incr);

	void setDuration(int dur);

	void incrementDuration(int incr);
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;
