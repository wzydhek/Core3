/*
 * GuildList.h
 *
 *  Created on: Oct 27, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/guild/GuildObject.h"

class GuildList : public VectorMap<uint32, ManagedReference<GuildObject*> > {
public:
	GuildList();
};
