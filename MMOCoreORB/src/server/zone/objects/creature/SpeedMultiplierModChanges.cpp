#include "SpeedMultiplierModChanges.h"

SpeedModChange::SpeedModChange() {
	newSpeed = 0;
}

SpeedModChange::SpeedModChange(float speed) {
	newSpeed = speed;
	timeStamp.updateToCurrentTime();
}

SpeedModChange::SpeedModChange(float speed, Time& tm) {
	newSpeed = speed;
	timeStamp = tm;
}

SpeedModChange::SpeedModChange(const SpeedModChange& a) {
	newSpeed = a.newSpeed;
	timeStamp = a.timeStamp;
}

SpeedModChange& SpeedModChange::operator=(const SpeedModChange& a) {
	newSpeed = a.newSpeed;
	timeStamp = a.timeStamp;

	return *this;
}

float SpeedModChange::getNewSpeed() const {
	return newSpeed;
}

const Time& SpeedModChange::getTimeStamp() const {
	return timeStamp;
}

bool SpeedModChange::parseFromBinaryStream(ObjectInputStream* stream) {
	// TypeInfo<float>::parseFromBinaryStream(&newSpeed, stream);

	return false;
}

bool SpeedModChange::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

void server::zone::objects::creature::to_json(nlohmann::json& j, const SpeedModChange& v) {
	j["newSpeed"] = v.newSpeed;
	j["timeStamp"] = v.timeStamp;
}