/*
 * NonPlayerCreatureObjectTemplate.h
 *
 *  Created on: 10/07/2010
 *      Author: victor
 */

#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"

namespace templates {
namespace creature {

class NonPlayerCreatureObjectTemplate : public SharedCreatureObjectTemplate {

public:

	NonPlayerCreatureObjectTemplate();

	virtual ~NonPlayerCreatureObjectTemplate();

	void readObject(LuaObject* templateData);

	bool isNonPlayerCreatureObjectTemplate();
};

} // namespace creature
} // namespace templates

using namespace templates::creature;
