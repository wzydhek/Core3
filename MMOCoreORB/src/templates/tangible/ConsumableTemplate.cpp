#include "ConsumableTemplate.h"

ConsumableTemplate::ConsumableTemplate() {
	duration = 0;
	filling = 0;

	nutrition = 0.f;
	nutritionMin = 0.f;
	nutritionMax = 0.f;

	effectType = 0;

	fillingMin = 0;
	fillingMax = 0;
	flavorMin = 0;
	flavorMax = 0;
	quantityMin = 0;
	quantityMax = 0;

	buffCRC = 0;

	consumableType = 0;
	foragedFood = 0;
}

ConsumableTemplate::~ConsumableTemplate() {
}

void ConsumableTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	duration = templateData->getIntField("duration");
	filling = templateData->getIntField("filling");
	nutrition = templateData->getFloatField("nutrition");

	effectType = templateData->getIntField("effectType");

	eventType.removeAll();

	LuaObject eventTypes = templateData->getObjectField("eventTypes");

	for (int i = 1; i <= eventTypes.getTableSize(); ++i) {
		eventType.add(eventTypes.getIntAt(i));
	}

	eventTypes.pop();

	fillingMin = templateData->getIntField("fillingMin");
	fillingMax = templateData->getIntField("fillingMax");

	flavorMin = templateData->getIntField("flavorMin");
	flavorMax = templateData->getIntField("flavorMax");
	nutritionMin = templateData->getFloatField("nutritionMin");
	nutritionMax = templateData->getFloatField("nutritionMax");
	quantityMin = templateData->getIntField("quantityMin");
	quantityMax = templateData->getIntField("quantityMax");

	modifiers.removeAll();

	LuaObject mods = templateData->getObjectField("modifiers");

	for (int i = 1; i <= mods.getTableSize(); i += 2) {
		String attribute = mods.getStringAt(i);
		float value = mods.getFloatAt(i + 1);

		modifiers.put(attribute, value);
	}

	mods.pop();

	buffName = templateData->getStringField("buffName");
	buffCRC = templateData->getIntField("buffCRC");

	speciesRestriction = templateData->getStringField("speciesRestriction");
	// consumableType = templateData->getIntField("consumableType");
	foragedFood = templateData->getIntField("foragedFood");
}

uint32 ConsumableTemplate::getBuffCRC() const {
	return buffCRC;
}

String& ConsumableTemplate::getBuffName() {
	return buffName;
}

int ConsumableTemplate::getConsumableType() const {
	return consumableType;
}

int ConsumableTemplate::getForagedFood() const {
	return foragedFood;
}

int ConsumableTemplate::getDuration() const {
	return duration;
}

int ConsumableTemplate::getEffectType() const {
	return effectType;
}

int ConsumableTemplate::getFilling() const {
	return filling;
}

int ConsumableTemplate::getFillingMax() const {
	return fillingMax;
}

int ConsumableTemplate::getFillingMin() const {
	return fillingMin;
}

int ConsumableTemplate::getFlavorMax() const {
	return flavorMax;
}

int ConsumableTemplate::getFlavorMin() const {
	return flavorMin;
}

VectorMap<String, float>* ConsumableTemplate::getModifiers() {
	return &modifiers;
}

Vector<int>* ConsumableTemplate::getEventTypes() {
	return &eventType;
}

float ConsumableTemplate::getNutrition() const {
	return nutrition;
}

float ConsumableTemplate::getNutritionMax() const {
	return nutritionMax;
}

float ConsumableTemplate::getNutritionMin() const {
	return nutritionMin;
}

int ConsumableTemplate::getQuantityMax() const {
	return quantityMax;
}

int ConsumableTemplate::getQuantityMin() const {
	return quantityMin;
}

String& ConsumableTemplate::getSpeciesRestriction() {
	return speciesRestriction;
}