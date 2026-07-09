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
	SlicingToolTemplate();

	~SlicingToolTemplate();

	void readObject(LuaObject* templateData) override;

	float getEffectiveness() const;

};
