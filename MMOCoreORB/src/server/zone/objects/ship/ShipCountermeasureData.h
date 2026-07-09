#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

class ShipCountermeasureData : public Object {
public:
	enum CountermeasureType : int {
		MK1 = 0,
		MK2 = 1,
		MK3 = 2,
		MK4 = 3,
		MK5 = 4,
		AI1 = 5,
		AI2 = 6
	};

	static int getLauncherAmmoType(const String& dataName);

	static int getCountermeasureAmmoType(uint32 objectCRC);

protected:
	int countermeasureType;
	String appearance;

	int minCount;
	int maxCount;
	float minSpeed;
	float maxSpeed;
	float scatterAngle;

public:
	ShipCountermeasureData();

	void readObject(DataTableRow* row);

	// set
	void setCountermeasureType(int value);

	void setAppearance(const String& value);

	void setMinCount(int value);

	void setMaxCount(int value);

	void setMinSpeed(int value);

	void setMaxSpeed(int value);

	void setScatterAngle(int value);

	// get
	int getCountermeasureType() const;

	const String& getAppearance() const;

	int getMinCount() const;

	int getMaxCount() const;

	int getMinSpeed() const;

	int getMaxSpeed() const;

	int getScatterAngle() const;
};
