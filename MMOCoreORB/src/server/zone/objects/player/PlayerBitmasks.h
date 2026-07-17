/*
 * PlayerBitmasks.h
 *
 * Created on: 08/19/22
 * Author: H
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

//#define DEBUG_PLAYERBITMASKS

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerBitmasks : public Serializable, public ReadWriteLock {
	uint32 playerBitmask[4];
public:
	enum {
		LFG				= 0,
		NEWBIEHELPER	= 1,
		ROLEPLAYER		= 2,
		AFK				= 7,
		LD				= 8,
		FACTIONRANK		= 9,
		ANONYMOUS		= 127
	};

	PlayerBitmasks();

	PlayerBitmasks(const PlayerBitmasks& bitmasks);

	PlayerBitmasks& operator=(const PlayerBitmasks& bitmasks);

	inline void addSerializableVariables();

public:
	friend void to_json(nlohmann::json& j, const PlayerBitmasks& b);

	void setOneBit(const uint32 bitmask);

	void clearOneBit(const uint32 bitmask);

	bool hasPlayerBit(const uint32 bitmask) const;

	uint32 getBitmask(int index) const;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;
