/*
 * DroidCustomKitTemplate.h
 *
 *  Created on: 11/29/2013
 *      Author: Klivian
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class DroidCustomKitTemplate : public SharedTangibleObjectTemplate {

public:
	DroidCustomKitTemplate();

	~DroidCustomKitTemplate();

	void readObject(LuaObject* templateData);

	bool isDroidCustomKitTemplate();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;