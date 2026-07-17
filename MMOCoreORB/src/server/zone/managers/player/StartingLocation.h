/*
 * StartingLocation.h
 *
 *  Created on: Apr 4, 2011
 *      Author: crush
 */

#pragma once

#include "templates/datatables/DataTableRow.h"
#include "engine/service/Message.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class StartingLocation : public Object {
	String zoneName;
	String location;
	String planet;
	String cell;
	String image;
	String description;

	float x;
	float y;
	float z;
	float radius;
	float heading;

public:
	StartingLocation();

	StartingLocation(const StartingLocation& sl);

	StartingLocation& operator=(const StartingLocation& sl);

	int compareTo(const StartingLocation& sl) const;

	void parseFromDataTableRow(DataTableRow* row);

	void insertToMessage(Message* msg);

	float getX() const;

	float getY() const;

	float getZ() const;

	float getHeading() const;

	uint64 getCell() const;

	String getZoneName() const;

	String getLocation() const;
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
