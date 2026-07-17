/*
 * ConsumableTemplate.h
 *
 *  Created on: 15/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class ConsumableTemplate : public SharedTangibleObjectTemplate {
	int duration;
	int filling;

	float nutrition;

	float nutritionMin;
	float nutritionMax;

	int effectType;
	Vector<int> eventType;

	int fillingMin;
	int fillingMax;
	int flavorMin;
	int flavorMax;

	int quantityMin;
	int quantityMax;

	VectorMap<String, float> modifiers;
	String buffName;
	uint32 buffCRC;

	String speciesRestriction;

	int consumableType;
	int foragedFood;

public:
	ConsumableTemplate();

	~ConsumableTemplate();

	void readObject(LuaObject* templateData);

    uint32 getBuffCRC() const;

    String& getBuffName();

    int getConsumableType() const;

    int getForagedFood() const;

    int getDuration() const;

    int getEffectType() const;

    int getFilling() const;

    int getFillingMax() const;

    int getFillingMin() const;

    int getFlavorMax() const;

    int getFlavorMin() const;

	VectorMap<String, float>* getModifiers();

	Vector<int>* getEventTypes();

	float getNutrition() const;

	float getNutritionMax() const;

	float getNutritionMin() const;

	int getQuantityMax() const;

	int getQuantityMin() const;

	String& getSpeciesRestriction();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;