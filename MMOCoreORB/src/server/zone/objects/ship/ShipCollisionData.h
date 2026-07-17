#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/ship/ComponentSlots.h"
#include "server/zone/objects/ship/ShipChassisData.h"
#include "templates/tangible/ship/SharedShipObjectTemplate.h"
#include "server/zone/objects/ship/ShipCollisionHardpoint.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipCollisionData : public Object, public Logger {
public:
	enum CollisionVolumeType : int {
		INVALID = -1,
		RADIUS = 0,
		SPHERE = 1,
		MESH = 2,
		BOX = 3,
	};

protected:
	VectorMap<String, VectorMap<uint32, ShipCollisionHardpoint>> hardpointMap;
	VectorMap<uint32, uint32> slotWeights;
	Vector<uint32> targetableSlots;
	int hardpointSize;

	const AppearanceTemplate* appearance;
	Sphere boundingSphere;
	Sphere chassisSphere;
	AABB chassisBox;
	int volumeType;

public:
	ShipCollisionData(SharedShipObjectTemplate* templateData, const ShipChassisData* chassisData);

	void setCollisionData(SharedShipObjectTemplate* templateData);

	void setClientData(SharedShipObjectTemplate* shipTemplate);

	void setComponentData(SharedShipObjectTemplate* templateData, const ShipChassisData* chassisData);

	void setSlotWeights(SharedShipObjectTemplate* templateData, const ShipChassisData* chassisData);

	void addCollisionHardpoint(SharedShipObjectTemplate* shipTemplate, const String& componentName, const String& hardpointName, int slot, float radius);

	void addCollisionHardpoint(SharedShipObjectTemplate* shipTemplate, const String& componentName, const String& attachmentName, const String& hardpointName, int slot, float radius);

	int getBoundingVolumeType(const BaseBoundingVolume* volume) const;

	bool isIdentityMatrix(const Matrix4& matrix) const;

	Sphere getChassisBoundingSphere(const BaseBoundingVolume* volume) const;

	Sphere getHardpointBoundingSphere(const Sphere& sphere, const Vector3& position, const Matrix4& rotation) const;

	Sphere getHardpointBoundingSphere(const AABB& box, const Vector3& position, const Matrix4& rotation) const;

	AABB getHardpointBoundingBox(const AABB& box, const Vector3& position, const Matrix4& rotation) const;

	String getAttachmentTemplatePath(const String& attachmentName, int slot) const;

	String getShipFileName(const String& shipName) const;

	const VectorMap<uint32, ShipCollisionHardpoint>& getHardpoints(const String& slotName) const;

	const VectorMap<uint32, ShipCollisionHardpoint>& getHardpoints(uint32 slot) const;

	const Vector<uint32>& getTargetableSlots() const;

	int getSlotWeight(uint32 slot) const;

	const AppearanceTemplate* getAppearanceTemplate() const;

	const Sphere& getBoundingSphere() const;

	const Sphere& getChassisSphere() const;

	const AABB& getChassisBox() const;

	int getVolumeType() const;

	int getHardpointSize() const;

	String toDebugString(bool includeHardpoints = true) const;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
