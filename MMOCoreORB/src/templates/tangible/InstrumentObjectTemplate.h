/*
 * InstrumentObjectTemplate.h
 *
 *  Created on: 22/09/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class InstrumentObjectTemplate : public SharedTangibleObjectTemplate {
	int instrumentType;

public:
	InstrumentObjectTemplate() {
		instrumentType = 0;
	}

	void readObject(LuaObject* templateData) override {
		SharedTangibleObjectTemplate::readObject(templateData);

		instrumentType = templateData->getIntField("instrumentType");
	}

	inline int getInstrumentType() const {
		return instrumentType;
	}

	bool isInstrumentObjectTemplate() const override {
		return true;
	}
};
