/*
 * CustomizationData.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

namespace templates {
namespace customization {

class CustomizationData : public Object {
	String speciesGender;
	String customizationGroup;
	String type;
	String customizationName;
	String variables;
	bool isScale;
	bool reverse;
	String colorLinked;
	String colorLinkedtoSelf0;
	String colorLinkedtoSelf1;
	float cameraYaw;
	bool discrete;
	bool randomizable;
	bool randomizableGroup;
	bool isVarHairColor;
	String imageDesignSkillMod;
	int skillModValue;
	String modificationType;
	float minScale;
	float maxScale;

public:
	CustomizationData();

	CustomizationData(const CustomizationData& c);

	CustomizationData& operator=(const CustomizationData& c);

	void parseRow(DataTableRow* row);

	const String& getCustomizationGroup() const;

	const String& getType() const;

	const String& getCustomizationName() const;

	const String& getVariables() const;

	bool getIsScale() const;

	bool getReverse() const;

	const String& getColorLinked() const;

	const String& getColorLinkedtoSelf0() const;

	const String& getColorLinkedtoSelf1() const;

	float getCameraYaw() const;

	bool getDiscrete() const;

	bool getRandomizable() const;

	bool getRandomizableGroup() const;

	bool getIsVarHairColor() const;

	const String& getImageDesignSkillMod() const;

	int getSkillModValue() const;

	const String& getModificationType() const;

	bool isPhysicalModificationType() const;

	bool isCosmeticModificationType() const;

	bool isHorizontalSlider() const;

	bool isColorPicker() const;

	float getMinScale() const;

	float getMaxScale() const;

	void setMinScale(float min);

	void setMaxScale(float max);

};

} // namespace customization
} // namespace templates

using namespace templates::customization;
