/*
 * GuildMemberList.h
 *
 *  Created on: Oct 27, 2010
 *      Author: crush
 */

#pragma once

#include "engine/engine.h"
#include "GuildMemberInfo.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace guild {

	class GuildMemberList : public VectorMap<uint64, GuildMemberInfo> {
		public:

		GuildMemberList();
	};
   }
  }
 }
}

using namespace server::zone::objects::guild;
