/*
 * GuildList.h
 *
 *  Created on: Oct 27, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/guild/GuildObject.h"

namespace server {
namespace zone {
namespace managers {
namespace guild {

class GuildList : public VectorMap<uint32, ManagedReference<GuildObject*> > {
public:
	GuildList();
};

} // namespace guild
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::guild;
