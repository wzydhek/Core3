/*
 * PatrolPathTemplate.h
 *
 *  Created on: 20/01/2012
 *      Author: victor
 */

#pragma once

#include "templates/mobile/PatrolPathNode.h"

namespace templates {
namespace mobile {

class PatrolPathTemplate : public Object {
	VectorMap<String, PatrolPathNode> pathMap;
public:
	PatrolPathTemplate();

	PatrolPathTemplate(const PatrolPathTemplate& tmp);

	PatrolPathTemplate& operator=(const PatrolPathTemplate& tmp);

	void readObject(LuaObject* luaObject);
};

} // namespace mobile
} // namespace templates

using namespace templates::mobile;
