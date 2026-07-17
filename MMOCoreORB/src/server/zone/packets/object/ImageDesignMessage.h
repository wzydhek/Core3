/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ImageDesignStartMessage : public ObjectControllerMessage {
public:
	ImageDesignStartMessage(CreatureObject* object, CreatureObject* designer, CreatureObject* targetPlayer, uint64 tentID, const String& holoemote);
};

class ImageDesignRejectMessage : public ObjectControllerMessage {

public:
	ImageDesignRejectMessage(uint64 object, uint64 designer, uint64 client, uint64 tent, int type = 0);
};

class ImageDesignChangeMessage : public ObjectControllerMessage {

public:
	ImageDesignChangeMessage(uint64 object, uint64 designer, uint64 client, uint64 tent, int type = 0);
};


} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
