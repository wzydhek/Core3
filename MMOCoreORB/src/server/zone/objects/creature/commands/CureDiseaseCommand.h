/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "CurePackCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class CureDiseaseCommand : public CurePackCommand {

public:

	CureDiseaseCommand(const String& name, ZoneProcessServer* server);

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
