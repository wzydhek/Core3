/*
 * WorldCoordinate.h
 *
 *  Created on: 02/03/2011
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/cell/CellObject.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace scene {
   	   class SceneObject;
   }
  }
 }
}

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class WorldCoordinates : public Object {
protected:
	Vector3 point;
	ManagedReference<CellObject*> cell;

public:
	// Constructors
	WorldCoordinates();
	WorldCoordinates(const WorldCoordinates& c);
	WorldCoordinates(SceneObject* obj);
	WorldCoordinates(const Vector3& position, CellObject* cell);

	// Destructor
	~WorldCoordinates();

#ifdef CXX11_COMPILER
	WorldCoordinates(WorldCoordinates&& c);
#endif

	WorldCoordinates& operator=(const WorldCoordinates& c);

#ifdef CXX11_COMPILER
	WorldCoordinates& operator=(WorldCoordinates&& c);
#endif

	bool operator==(const WorldCoordinates& c);

	friend void to_json(nlohmann::json& j, const WorldCoordinates& c);

	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);

	bool isInRange(const WorldCoordinates& obj, float range) const;

	Vector3 getWorldPosition() const;

	void setCell(CellObject* obj);

	void setCoordinates(const Vector3& pos);

	void setX(float x);

	void setY(float y);

	void setZ(float z);

	const Vector3& getPoint() const;

	Vector3 getPoint();

	CellObject* getCell() const;

	float getX() const;

	float getY() const;

	float getZ() const;

	String toString() const;

	String toStringData() const;
};

void to_json(nlohmann::json& j, const WorldCoordinates& c);

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;
