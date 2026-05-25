/*
 * StartingLocationList.h
 *
 *  Created on: Apr 4, 2011
 *      Author: crush
 */

#pragma once

#include "StartingLocation.h"
#include "templates/datatables/DataTableIff.h"

class StartingLocationList : public SortedVector<StartingLocation> {

public:
	StartingLocationList() : SortedVector<StartingLocation>() {
	}

	inline int getTotalLocations() {
		return size();
	}

	void parseFromIffStream(IffStream* iffStream) {
		DataTableIff dtiff;
		dtiff.readObject(iffStream);

		for (int i = 0; i < dtiff.getTotalRows(); ++i) {
			DataTableRow* row = dtiff.getRow(i);

			if (row == nullptr)
				continue;

			StartingLocation loc;
			loc.parseFromDataTableRow(row);

			add(loc);
		}
	}

	void insertToMessage(Message* msg) {
		msg->insertInt(size());

		for (int i = 0; i < size(); ++i)
			get(i).insertToMessage(msg);
	}
};
