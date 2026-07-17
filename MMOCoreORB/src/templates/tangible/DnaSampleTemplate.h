/*
 * DiceTemplate.h
 *
 *  Created on: March 16, 2012
 *	  Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DnaSampleTemplate: public SharedTangibleObjectTemplate {
protected:

	float cleverness;
	float endurance;
	float fierceness;
	float power;
	float intellect;
	float courage;
	float dependability;
	float dexterity;
	float fortitude;
	float hardiness;

	String source;
	String special1;
	String special2;
	bool ranged;
	String quality;

	int armorRating;
	float kinResist;
	float energyResist;
	float blastResist;
	float coldResist;
	float heatResist;
	float elecResist;
	float acidResist;
	float stunResist;
	float saberResist;

public:
	DnaSampleTemplate();

	~DnaSampleTemplate();

	void readObject(LuaObject* templateData);

	float getAcidResist() const;

	float getSaberResist() const;

	int getArmorRating() const;

	float getBlastResist() const;

	float getCleverness() const;

	float getColdResist() const;

	float getCourage() const;

	float getDependability() const;

	float getDexterity() const;

	float getElecResist() const;

	float getEndurance() const;

	float getEnergyResist() const;

	float getFierceness() const;

	float getFortitude() const;

	float getHardiness() const;

	float getHeatResist() const;

	float getIntellect() const;

	float getKinResist() const;

	float getPower() const;

	String getQuality() const;

	bool getRanged() const;

	String getSource() const;

	String getSpecial1() const;

	String getSpecial2() const;

	float getStunResist() const;

	void setAcidResist(float acidResist);

	void setSaberResist(float value);

	void setArmorRating(int armorRating);

	void setBlastResist(float blastResist);

	void setCleverness(float cleverness);

	void setColdResist(float coldResist);

	void setCourage(float courage);

	void setDependability(float dependability);

	void setDexterity(float dexterity);

	void setElecResist(float elecResist);

	void setEndurance(float endurance);

	void setEnergyResist(int energyResist);

	void setFierceness(float fierceness);

	void setFortitude(float fortitude);

	void setHardiness(float hardiness);

	void setHeatResist(float heatResist);

	void setIntellect(float intellect);

	void setKinResist(float kinResist);

	void setPower(float power);

	void setQuality(String quality);

	void setRanged(bool ranged);

	void setSource(String source);

	void setSpecial1(String special1);

	void setSpecial2(String special2);

	void setStunResist(float stunResist);

	bool isDnaSampleTemplate();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;