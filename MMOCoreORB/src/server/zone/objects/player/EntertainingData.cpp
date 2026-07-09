#include "EntertainingData.h"

EntertainingData::EntertainingData() {
	duration = 0;
	strength = 0;
	timeStarted = time(0);
	addSerializableVariables();
}

EntertainingData::EntertainingData(const EntertainingData& d) : Object(), Serializable() {
	duration = d.duration;
	strength = d.strength;
	timeStarted = d.timeStarted;

	addSerializableVariables();
}

EntertainingData& EntertainingData::operator=(const EntertainingData& d) {
	if (this == &d)
		return *this;

	duration = d.duration;
	strength = d.strength;
	timeStarted = d.timeStarted;

	return *this;
}

void EntertainingData::addSerializableVariables() {
	addSerializableVariable("duration", &duration);
	addSerializableVariable("strength", &strength);
}

int EntertainingData::getDuration() {
	return duration;
}

int EntertainingData::getStrength() {
	return strength;
}
int EntertainingData::getTimeStarted() {
	return timeStarted;
}
void EntertainingData::setStrength(int str) {
	strength = str;
}

void EntertainingData::incrementStrength(int incr) {
	strength += incr;
}

void EntertainingData::setDuration(int dur) {
	duration = dur;
}

void EntertainingData::incrementDuration(int incr) {
	duration += incr;
}