/*
 * ShipChassisTemplate.h
 *
 *  Created on: 12/22/2023
 *  Author: hakry
 */

#pragma once

#include "templates/tangible/ship/ShipComponentTemplate.h"

class ShipChassisTemplate : public ShipComponentTemplate {
	String chassisDeed;
	String certificationRequired;
	Vector<String> skillsRequired;

	int dealerFee;
	bool pob;

public:
	ShipChassisTemplate();

	~ShipChassisTemplate();

	void readObject(LuaObject* templateData);

	// Accessors
	String getChassisDeed();

	String getCertificationsRequired();

	int getTotalSkillsRequired();

	String getSkillRequired(int index);

	int getDealerFee();

	bool isPob();

	bool isShipChassisTemplate();
};
