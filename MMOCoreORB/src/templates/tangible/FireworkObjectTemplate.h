/*
 * FireworkObjectTemplate.h
 *
 *  Created on: May 7, 2010
 *      Author: swgemu
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class FireworkObjectTemplate : public SharedTangibleObjectTemplate {
	String fireworkObject;
	bool isShow;

public:
	FireworkObjectTemplate();

	~FireworkObjectTemplate();

	void readObject(LuaObject* templateData);

    String getFireworkObject() const;

    bool isFireworkShow();

	bool isFireworkObjectTemplate();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
