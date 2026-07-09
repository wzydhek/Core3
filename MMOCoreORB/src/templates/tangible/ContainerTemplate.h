/*
 * ContainerTemplate.h
 *
 *  Created on: Mar 9, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class ContainerTemplate : public SharedTangibleObjectTemplate {
	bool lock;

public:
	ContainerTemplate();

	~ContainerTemplate();

	void readObject(LuaObject* templateData);

	bool getLocked() const;

};
