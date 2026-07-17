/*
 * DiceTemplate.h
 *
 *  Created on: March 16, 2012
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DiceTemplate: public SharedTangibleObjectTemplate {
protected:

	int sides;
	String sidesText;
	String selfSingleResult;
	String othersSingleResult;
	String selfManyResult;
	String othersManyResult;

public:
	DiceTemplate();

	~DiceTemplate();

	void readObject(LuaObject* templateData);

	int getSides();

	String getSidesText();

	String getSelfSingleResult();

	String getOthersSingleResult();

	bool isDiceTemplate();

	bool isChanceCube();

	bool isConfigurable();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;