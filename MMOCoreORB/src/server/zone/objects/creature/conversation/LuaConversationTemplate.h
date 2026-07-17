/*
 * LuaConversationTemplate.h
 *
 *  Created on: 04/01/2012
 *      Author: victor
 */

#pragma once

#include "ConversationTemplate.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace conversation {

class LuaConversationTemplate {
public:
	// Constants
	static const char className[];
	static Luna<LuaConversationTemplate>::RegType Register[];

	// Initialize the pointer
	LuaConversationTemplate(lua_State *L);
	~LuaConversationTemplate();

	int _setObject(lua_State* L);
	// Methods we will need to use
	int getScreen(lua_State* L);
	int getInitialScreen(lua_State* L);

private:
	// The pointer to the 'real object' defined in object.cc
	Reference<ConversationTemplate*> realObject;
};

} // namespace conversation
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::conversation;
