/*
 * CreationData.h
 *
 *  Created on: Apr 21, 2011
 *      Author: crush
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace player {
namespace creation {

class RacialCreationData : public Object {
	Vector<int> minAttributes;
	Vector<int> maxAttributes;
	Vector<int> modAttributes;
	int totalAttributes;

public:
	RacialCreationData();

	RacialCreationData(const RacialCreationData& cd);

	RacialCreationData& operator=(const RacialCreationData& cd);

	void parseAttributeData(const DataTableRow* row);

	void parseRacialModData(const DataTableRow* row);

	int getAttributeMin(int idx) const;

	int getAttributeMax(int idx) const;

	int getAttributeMod(int idx) const;

	int getAttributeTotal() const;

	String toString() const;
};

}
}
}
}
}

using namespace server::zone::managers::player::creation;
