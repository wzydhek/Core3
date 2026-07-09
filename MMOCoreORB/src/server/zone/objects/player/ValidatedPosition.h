/*
 * ValidatedPosition.h
 *
 *  Created on: 27/11/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
 namespace zone {
  class ZoneServer;

  namespace objects {
   namespace scene {
    class SceneObject;
   }
  }
 }
}

class ValidatedPosition : public Serializable {
	SerializableVector3 point;
	uint64 parent;
public:
	ValidatedPosition();

	ValidatedPosition(const Vector3& pos);

	ValidatedPosition(const ValidatedPosition& a);

	ValidatedPosition& operator=(const ValidatedPosition& a);

	friend void to_json(nlohmann::json& j, const ValidatedPosition& pos);

	Vector3 getWorldPosition(server::zone::ZoneServer* zoneServer);

	void update(server::zone::objects::scene::SceneObject* object);

	uint64 getParent() const;

	const Vector3& getPosition() const;

	void setParent(uint64 par);

	void setPosition(const Vector3& pos);

	void setPosition(float x, float z, float y);

private:
	void addSerVariables();

};
