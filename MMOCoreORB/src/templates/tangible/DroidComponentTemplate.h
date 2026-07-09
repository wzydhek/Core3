/*
 * DroidComponentTemplate.h
 *
 *  Created on: Aug 21, 2014
 *      Author: washu
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DroidComponentTemplate : public SharedTangibleObjectTemplate {

public:
	DroidComponentTemplate();

	~DroidComponentTemplate();

	void readObject(LuaObject* templateData);

	bool isDroidComponentTemplate();

};
