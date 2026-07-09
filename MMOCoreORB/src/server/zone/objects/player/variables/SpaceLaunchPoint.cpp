#include "SpaceLaunchPoint.h"

SpaceLaunchPoint::SpaceLaunchPoint() : Object() {
	groundZoneName = "";
	cityName = "";
}

SpaceLaunchPoint::SpaceLaunchPoint(const SpaceLaunchPoint& point) : Object() {
	initialize(point);
}

SpaceLaunchPoint& SpaceLaunchPoint::operator=(const SpaceLaunchPoint& point) {
	if (this == &point)
		return *this;

	initialize(point);

	return *this;
}

void to_json(nlohmann::json& j, const SpaceLaunchPoint& l) {
	j["groundZoneName"] = l.groundZoneName;
	j["cityName"] = l.cityName;
	j["location"] = l.location;
}

bool SpaceLaunchPoint::toBinaryStream(ObjectOutputStream* stream) {
	groundZoneName.toBinaryStream(stream);
	cityName.toBinaryStream(stream);
	location.toBinaryStream(stream);

	return true;
}

bool SpaceLaunchPoint::parseFromBinaryStream(ObjectInputStream* stream) {
	groundZoneName.parseFromBinaryStream(stream);
	cityName.parseFromBinaryStream(stream);
	location.parseFromBinaryStream(stream);

	return true;
}

void SpaceLaunchPoint::initialize(const SpaceLaunchPoint& point) {
	groundZoneName = point.groundZoneName;
	cityName = point.cityName;
	location = point.location;
}

void SpaceLaunchPoint::setGroundZoneName(String zoneName) {
	groundZoneName = zoneName;
}

void SpaceLaunchPoint::setCityName(String name) {
	cityName = name;
}

void SpaceLaunchPoint::setLocation(float x, float z, float y) {
	location.setX(x);
	location.setZ(z);
	location.setY(y);
}

void SpaceLaunchPoint::setLocation(Vector3 loc) {
	location = loc;
}

String SpaceLaunchPoint::getGoundZoneName() {
	return groundZoneName;
}

String SpaceLaunchPoint::getCityName() {
	return cityName;
}

Vector3 SpaceLaunchPoint::getLocation() {
	return location;
}