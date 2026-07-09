/*
 * PowerupTemplate.h
 *
 *  Created on: Mar 06, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"
#include "templates/tangible/PowerupStat.h"

class PowerupTemplate: public SharedTangibleObjectTemplate {
protected:

	String baseName;
	String pupType;

	Vector<PowerupStat> primaryAttributes;
	Vector<PowerupStat> secondaryAttributes;

public:
	PowerupTemplate();

	~PowerupTemplate();

	PowerupStat getRandomPrimaryAttribute();

	bool hasPrimaryAttribute();

	Vector<PowerupStat> getSecondaryAttributes();

	int getTotalSecondaryAttributes();

	bool hasSecondaryAttribute();

	String& getBaseName();

	String& getType();

	void readObject(LuaObject* templateData);

	void parseVariableData(const String& varName, LuaObject* data);
};
