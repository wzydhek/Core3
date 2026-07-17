/*
 * SpaceLaunchPoint.h
 *
 *	Created on: Jan. 22, 2023
 *	Author: H
 */

#pragma once

#include "engine/util/json_utils.h"
#include "engine/util/u3d/Vector3.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace variables {

class SpaceLaunchPoint : public Object {
	String groundZoneName;
	String cityName;
	Vector3 location;

public:
	SpaceLaunchPoint();

	SpaceLaunchPoint(const SpaceLaunchPoint& point);

	SpaceLaunchPoint& operator=(const SpaceLaunchPoint& point);

	friend void to_json(nlohmann::json& j, const SpaceLaunchPoint& l);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	void initialize(const SpaceLaunchPoint& point);

	void setGroundZoneName(String zoneName);

	void setCityName(String name);

	void setLocation(float x, float z, float y);

	void setLocation(Vector3 loc);

	String getGoundZoneName();

	String getCityName();

	Vector3 getLocation();
};

} // namespace variables
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::variables;
