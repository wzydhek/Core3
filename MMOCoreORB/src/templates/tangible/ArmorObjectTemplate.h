/*
 * ArmorObjectTemplate.h
 *
 *  Created on: 01/06/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class ArmorObjectTemplate : public SharedTangibleObjectTemplate {
	int healthEncumbrance;
	int actionEncumbrance;
	int mindEncumbrance;

	int rating;

	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;

	int vulnerabilites;
	int specialResists;

	uint8 hitLocation;

public:

	// hit locations (for serverside armor checks)
	enum SuitLocations { NOLOCATION = 0x0, CHEST = 0x1, ARMS = 0x2, LEGS = 0x4, HEAD = 0x8 };

	ArmorObjectTemplate();

	~ArmorObjectTemplate();

	void readObject(LuaObject* templateData);

	float getAcid() const;

	int getActionEncumbrance() const;

	float getBlast() const;

	float getCold() const;

	float getElectricity() const;

	float getEnergy() const;

	int getHealthEncumbrance() const;

	float getHeat() const;

	float getKinetic() const;

	float getLightSaber() const;

	int getMindEncumbrance() const;

	int getRating() const;

	float getStun() const;

	int getVulnerabilites() const;

	int getSpecialResists() const;

	int getHitLocation() const;

	void setAcid(float acid);

	void setActionEncumbrance(int actionEncumbrance);

	void setBlast(float blast);

	void setCold(float cold);

	void setElectricity(float electricity);

	void setEnergy(float energy);

	void setHealthEncumbrance(int healthEncumbrance);

	void setHeat(float heat);

	void setKinetic(float kinetic);

	void setLightSaber(float lightSaber);

	void setMindEncumbrance(int mindEncumbrance);

	void setRating(int rating);

	void setStun(float stun);

	void setHitLocation(int hitLocation);

	bool isArmorObjectTemplate();
};
