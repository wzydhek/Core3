/*
 * SignTemplate.h
 *
 *  Created on: 3/15/2014
 *      Author: Klivian
 */

#pragma once

#include "templates/ChildObject.h"

namespace templates {
namespace building {

class SignTemplate : public ChildObject {
	String requiredSkill;
	String suiItem;

public:
	SignTemplate();

	SignTemplate(const SignTemplate& obj);

	SignTemplate& operator=(const SignTemplate& obj);

	void parseFromLua(LuaObject* luaObject);

	const String& getSuiItem() const;

	const String& getRequiredSkill() const;

};

} // namespace building
} // namespace templates

using namespace templates::building;
