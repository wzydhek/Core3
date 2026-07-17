/*
 * StartingLocationList.h
 *
 *  Created on: Apr 4, 2011
 *      Author: crush
 */

#pragma once

#include "StartingLocation.h"
#include "templates/datatables/DataTableIff.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class StartingLocationList : public SortedVector<StartingLocation> {

public:
	StartingLocationList();

	int getTotalLocations();

	void parseFromIffStream(IffStream* iffStream);

	void insertToMessage(Message* msg);
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
