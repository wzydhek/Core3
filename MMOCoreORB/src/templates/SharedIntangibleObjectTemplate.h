/*
 * SharedIntangibleObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"

class SharedIntangibleObjectTemplate : public SharedObjectTemplate {
protected:


public:
	SharedIntangibleObjectTemplate();

	~SharedIntangibleObjectTemplate();

	void readObject(IffStream* iffStream);

	void readObject(LuaObject* templateData);

};
