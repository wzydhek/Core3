/*
 * EntertainingData.h
 *
 *  Created on: 20/09/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

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
