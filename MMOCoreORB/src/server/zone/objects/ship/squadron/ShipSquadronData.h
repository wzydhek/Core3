#pragma once

namespace server {
	namespace zone {
		namespace objects {
			namespace ship {
				class ShipObject;
			}
		}
	}
}

#include "server/zone/objects/tangible/TangibleObject.h"
#include "ShipSquadronFormation.h"

class ShipSquadronDataEntry : public Object {
protected:
	Vector3 formation;
	Vector3 position;
	float speed;

public:
	ShipSquadronDataEntry();

	const Vector3& getFormation() const;

	const Vector3& getPosition() const;

	float getSpeed() const;

	void setFormation(const Vector3& value);

	void setPosition(const Vector3& value);

	void setSpeed(float value);
};

class ShipSquadronData : public Object, public Logger {
private:
	constexpr static float AUTO_RADIUS_MODIFIER = 5.f;

protected:
	Vector<ShipSquadronDataEntry> squadronData;
	float formationRadius;
	int formationType;

public:
	ShipSquadronData();

	ShipSquadronData(ShipObject* ship);

	~ShipSquadronData();

	int size() const;

	int getFormationType() const;

	float getFormationRadius() const;

	void setFormationType(int value);

	void setFormationRadius(float value);

	void add(ShipObject* ship);

	void remove(int index);

	void makeLeader(ShipObject* ship);

	void setFormation(int index, float radius);

	void setFormation(int index, const Vector3& position);

	void setPosition(int index, const Vector3& position);

	void setSpeed(int index, float speed);

	Vector3 getFormation(int index) const;

	Vector3 getPosition(int index) const;

	float getSpeed(int index) const;

	float getFormationSpeed() const;
};
