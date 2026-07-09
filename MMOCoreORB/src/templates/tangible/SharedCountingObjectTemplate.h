/*
 * SharedCountingObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SharedCountingObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedCountingObjectTemplate();

	~SharedCountingObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);
};
