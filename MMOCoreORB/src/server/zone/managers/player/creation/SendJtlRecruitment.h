/*
 * SendJtlRecruitment.h
 *
 *  Created on: 2024-10-23
 *	Author: Hakry
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/chat/ChatManager.h"

namespace server {
namespace zone {
namespace managers {
namespace player {
namespace creation {

class SendJtlRecruitment : public Task {
	ManagedWeakReference<CreatureObject*> weakPlayer;

public:
	SendJtlRecruitment(CreatureObject* player);

	void run();
};

} // namespace creation
} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player::creation;
