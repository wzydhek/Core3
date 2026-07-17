/*
 * SurveyToolApproveRadioactiveSuiCallback.h
 *
 *  Created on: may 22, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/installation/factory/FactoryObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace factory {
namespace sui {

class InsertSchematicSuiCallback : public SuiCallback, public Logger {
public:
	InsertSchematicSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void handleInsertFactorySchem2(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);

	void handleInsertFactorySchem3(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};

} // namespace sui
} // namespace factory
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::factory::sui;
