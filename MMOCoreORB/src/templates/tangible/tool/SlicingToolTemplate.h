/*
 * SlicingToolTemplate.h
 *
 *  Created on: Mar 6, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SlicingToolTemplate : public SharedTangibleObjectTemplate {
private:
	float effectiveness;

public:
	SlicingToolTemplate() {
		effectiveness = 0;
	}

	~SlicingToolTemplate() {

	}

	void readObject(LuaObject* templateData) override {
		SharedTangibleObjectTemplate::readObject(templateData);

		effectiveness = templateData->getFloatField("effectiveness");
	}

	float getEffectiveness() const {
		return effectiveness;
	}

};
