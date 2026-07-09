/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SharedResourceContainerObjectTemplate : public SharedTangibleObjectTemplate {

public:
	SharedResourceContainerObjectTemplate();

	~SharedResourceContainerObjectTemplate();

	void readObject(LuaObject* templateData);

	void readObject(IffStream* iffStream);
};
