/*
 * VeteranReward.h
 *
 *  Created on: 5/22/2014
 *      Author: Klivian
 */

#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"
#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class VeteranReward : public Object {

protected:
	String templateFile;
	unsigned int milestone; // days
	bool oneTime;
	String description;
	bool jtlReward;

public:
	VeteranReward();

	VeteranReward(const VeteranReward& obj);

	VeteranReward& operator=(const VeteranReward& obj);

	void parseFromLua(LuaObject* luaObject);

	void setTemplateFile(const String& file);

	void setMilestone(unsigned int days);

	void setOneTime(bool flag);

	void setDescription(const String& desc);

	void setJtlReward(bool val);

	String& getTemplateFile();

	unsigned int getMilestone();

	bool isOneTime();

	String& getDescription();

	bool isJtlReward();
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
