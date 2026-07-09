#pragma once

#include "engine/engine.h"
#include "templates/appearance/AppearanceTemplate.h"

class ShipCollisionHardpoint : public Object {
protected:
	const AppearanceTemplate* appearance;
	String componentName;
	String hardpointName;

	Vector3 position;
	Sphere sphere;
	AABB box;

	Reference<Matrix4*> rotation;
	int volumeType;
	float radius;
	int slot;

	bool targetable;

public:
	ShipCollisionHardpoint();

	ShipCollisionHardpoint(const String& componentNameValue, const String& hardpointNameValue);

	void setAppearanceTemplate(const AppearanceTemplate* value);

	void setComponentName(const String& value);

	void setHardpointName(const String& value);

	void setPosition(const Vector3& value);

	void setSphere(const Sphere& value);

	void setBox(const AABB& value);

	void setRotation(Matrix4* value);

	void setVolumeType(int value);

	void setRadius(float value);

	void setSlot(int value);

	void setTargetable(bool value);

	const AppearanceTemplate* getAppearanceTemplate() const;

	const String& getComponentName() const;

	const String& getHardpointName() const;

	const Vector3& getPosition() const;

	const Sphere& getSphere() const;

	const AABB& getBox() const;

	const Matrix4* getRotation() const;

	int getVolumeType() const;

	float getRadius() const;

	int getSlot() const;

	bool isTargetable() const;

	String toDebugString() const;

	String matrixToDebugString() const;
};
