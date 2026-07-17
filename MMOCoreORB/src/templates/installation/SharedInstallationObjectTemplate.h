/*
 * SharedInstallationObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/tangible/SharedStructureObjectTemplate.h"

namespace templates {
namespace installation {

class SharedInstallationObjectTemplate : public SharedStructureObjectTemplate {
	uint32 installationType;
	unsigned int armorRating;
	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;
	float chanceHit;
	String weapon;
	String factionString;

public:
	SharedInstallationObjectTemplate();

	~SharedInstallationObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);

	virtual bool isSharedInstallationObjectTemplate();

	uint32 getInstallationType() const;

	unsigned int getArmorRating() const;

	float getKinetic() const;

	float getEnergy() const;

	float getElectricity() const;

	float getStun() const;

	float getBlast() const;

	float getHeat() const;

	float getCold() const;

	float getAcid() const;

	float getLightSaber() const;

	const String& getWeapon() const;

	float getChanceHit() const;

	const String& getFactionString() const;
};

} // namespace installation
} // namespace templates

using namespace templates::installation;
