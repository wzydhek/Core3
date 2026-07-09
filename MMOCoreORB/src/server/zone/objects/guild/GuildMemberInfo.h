/*
 * GuildMemberInfo.h
 *
 *  Created on: Oct 27, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

	class GuildObject;

	class GuildMemberInfo : public Object {
		uint64 playerID;
		String guildTitle;
		uint8 permissions;
		uint64 declaredAllegiance; // TODO: remove after wipe

	public:
		GuildMemberInfo();

		GuildMemberInfo(uint64 playerid);

		GuildMemberInfo(const GuildMemberInfo& gmi);

		int compareTo(const GuildMemberInfo& gmi) const;

		GuildMemberInfo& operator=(const GuildMemberInfo& gmi);

		friend void to_json(nlohmann::json& j, const GuildMemberInfo& m);

		bool toBinaryStream(ObjectOutputStream* stream);

		bool parseFromBinaryStream(ObjectInputStream* stream);

		uint64 getPlayerID();

		void setPlayerID(uint64 playerid);

		String& getGuildTitle();

		void setGuildTitle(const String& title);

		uint8 getPermissions();

		void setPermissions(uint8 permission);

		void addPermission(uint8 permission);

		void removePermission(uint8 permission);

		void togglePermission(uint8 permission);

		bool hasPermission(uint8 permission);
	};
}
}
}
}

using namespace server::zone::objects::guild;
