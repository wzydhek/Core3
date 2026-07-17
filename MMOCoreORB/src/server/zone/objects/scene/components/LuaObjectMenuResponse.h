/*
 * LuaObjectMenuResponse.h
 *
 *  Created on: 30/01/2012
 *      Author: Elvaron
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace components {

	class LuaObjectMenuResponse {
	public:
		// Constants
		static const char className[];
		static Luna<LuaObjectMenuResponse>::RegType Register[];

		// Initialize the pointer
		LuaObjectMenuResponse(lua_State *L);
		~LuaObjectMenuResponse();

		int _setObject(lua_State* L);
		int addRadialMenuItem(lua_State* L);
		int addRadialMenuItemToRadialID(lua_State* L);

	private:
		// The pointer to the 'real object' defined in object.cc
		ObjectMenuResponse* realObject;
	};


} // namespace components
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::components;
