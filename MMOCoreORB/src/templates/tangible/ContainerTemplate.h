/*
 * ContainerTemplate.h
 *
 *  Created on: Mar 9, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class ContainerTemplate : public SharedTangibleObjectTemplate {
	bool lock;

public:
	ContainerTemplate();

	~ContainerTemplate();

	void readObject(LuaObject* templateData);

	bool getLocked() const;

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;