#include "CustomizationData.h"

CustomizationData::CustomizationData() {
	isScale = false;
	reverse = false;
	cameraYaw = 0.f;
	discrete = false;
	randomizable = false;
	randomizableGroup = false;
	isVarHairColor = false;
	skillModValue = 0;
	minScale = 0.f;
	maxScale = 0.f;
}

CustomizationData::CustomizationData(const CustomizationData& c) : Object() {
	speciesGender = c.speciesGender;
	customizationGroup = c.customizationGroup;
	type = c.type;
	customizationName = c.customizationName;
	variables = c.variables;
	isScale = c.isScale;
	reverse = c.reverse;
	colorLinked = c.colorLinked;
	colorLinkedtoSelf0 = c.colorLinkedtoSelf0;
	colorLinkedtoSelf1 = c.colorLinkedtoSelf1;
	cameraYaw = c.cameraYaw;
	discrete = c.discrete;
	randomizable = c.randomizable;
	randomizableGroup = c.randomizableGroup;
	isVarHairColor = c.isVarHairColor;
	imageDesignSkillMod = c.imageDesignSkillMod;
	skillModValue = c.skillModValue;
	modificationType = c.modificationType;
	minScale = c.minScale;
	maxScale = c.maxScale;
}

CustomizationData& CustomizationData::operator=(const CustomizationData& c) {
	if (this == &c)
		return *this;

	speciesGender = c.speciesGender;
	customizationGroup = c.customizationGroup;
	type = c.type;
	customizationName = c.customizationName;
	variables = c.variables;
	isScale = c.isScale;
	reverse = c.reverse;
	colorLinked = c.colorLinked;
	colorLinkedtoSelf0 = c.colorLinkedtoSelf0;
	colorLinkedtoSelf1 = c.colorLinkedtoSelf1;
	cameraYaw = c.cameraYaw;
	discrete = c.discrete;
	randomizable = c.randomizable;
	randomizableGroup = c.randomizableGroup;
	isVarHairColor = c.isVarHairColor;
	imageDesignSkillMod = c.imageDesignSkillMod;
	skillModValue = c.skillModValue;
	modificationType = c.modificationType;
	minScale = c.minScale;
	maxScale = c.maxScale;

	return *this;
}

void CustomizationData::parseRow(DataTableRow* row) {
	try {
		row->getValue(0, speciesGender);
		row->getValue(1, customizationGroup);
		row->getValue(2, type);
		row->getValue(3, customizationName);
		row->getValue(4, variables);
		row->getValue(5, isScale);
		row->getValue(6, reverse);
		row->getValue(7, colorLinked);
		row->getValue(8, colorLinkedtoSelf0);
		row->getValue(9, colorLinkedtoSelf1);
		row->getValue(10, cameraYaw);
		row->getValue(11, discrete);
		row->getValue(12, randomizable);
		row->getValue(13, randomizableGroup);
		row->getValue(14, isVarHairColor);
		row->getValue(15, imageDesignSkillMod);
		row->getValue(16, skillModValue);
		row->getValue(17, modificationType);
	} catch (const Exception& e) {
		System::err << "CustomizationData::parse() exception: " << e.getMessage() << endl;
	}
}

const String& CustomizationData::getCustomizationGroup() const {
	return customizationGroup;
}

const String& CustomizationData::getType() const {
	return type;
}

const String& CustomizationData::getCustomizationName() const {
	return customizationName;
}

const String& CustomizationData::getVariables() const {
	return variables;
}

bool CustomizationData::getIsScale() const {
	return isScale;
}

bool CustomizationData::getReverse() const {
	return reverse;
}

const String& CustomizationData::getColorLinked() const {
	return colorLinked;
}

const String& CustomizationData::getColorLinkedtoSelf0() const {
	return colorLinkedtoSelf0;
}

const String& CustomizationData::getColorLinkedtoSelf1() const {
	return colorLinkedtoSelf1;
}

float CustomizationData::getCameraYaw() const {
	return cameraYaw;
}

bool CustomizationData::getDiscrete() const {
	return discrete;
}

bool CustomizationData::getRandomizable() const {
	return randomizable;
}

bool CustomizationData::getRandomizableGroup() const {
	return randomizableGroup;
}

bool CustomizationData::getIsVarHairColor() const {
	return isVarHairColor;
}

const String& CustomizationData::getImageDesignSkillMod() const {
	return imageDesignSkillMod;
}

int CustomizationData::getSkillModValue() const {
	return skillModValue;
}

const String& CustomizationData::getModificationType() const {
	return modificationType;
}

bool CustomizationData::isPhysicalModificationType() const {
	return (modificationType == "physical");
}

bool CustomizationData::isCosmeticModificationType() const {
	return (modificationType == "cosmetic");
}

bool CustomizationData::isHorizontalSlider() const {
	return (type == "hslider");
}

bool CustomizationData::isColorPicker() const {
	return (type == "color");
}

float CustomizationData::getMinScale() const {
	return minScale;
}

float CustomizationData::getMaxScale() const {
	return maxScale;
}

void CustomizationData::setMinScale(float min) {
	minScale = min;
}

void CustomizationData::setMaxScale(float max) {
	maxScale = max;
}