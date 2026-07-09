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
	InstrumentObjectTemplate();

	void readObject(LuaObject* templateData) override;

	int getInstrumentType() const;

	bool isInstrumentObjectTemplate() const override;
};
