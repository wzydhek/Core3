/*
 * WaypointChatParameter.h
 *
 *  Created on: Nov 12, 2010
 *      Author: crush
 */

#pragma once

#include "server/chat/ChatParameter.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace waypoint {
	class WaypointObject;
}
}
}
}

using namespace server::zone::objects::waypoint;

namespace server {
namespace chat {

class WaypointChatParameter : public ChatParameter, public Serializable {
protected:
	UnicodeString waypointName;
	uint64 pointerParameter;
	uint64 cellID;
	uint32 planetCRC;
	uint32 unknownInt;
	float positionX;
	float positionY;
	float positionZ;
	byte color;
	bool active;

	void addSerializableVariables();

	void insertHeaderToMessage(Message* message) const override;

	void addToPacketStream(Message* packet) const override;

public:
	WaypointChatParameter();
	WaypointChatParameter(WaypointObject* waypoint);
	WaypointChatParameter(const WaypointChatParameter& custom);

	friend void to_json(nlohmann::json& j, const WaypointChatParameter& p);

	WaypointChatParameter& operator=(const WaypointChatParameter& par);

	void parse(Message* message) override;

	void set(WaypointObject* waypoint);
	void set(const UnicodeString& name, float x, float z, float y, uint32 planetcrc, uint64 pointer = 0, uint64 cellid = 0, byte clr = 1, bool actv = false);

	const UnicodeString& getWaypointName() const;

	uint64 getPointerParameter() const;

	uint64 getCellID() const;

	uint32 getPlanetCRC() const;

	uint32 getUnknownInt() const;

	float getPositionX() const;

	float getPositionY() const;

	float getPositionZ() const;

	byte getColor() const;

	bool isActive() const;
};

}
}

using namespace server::chat;
