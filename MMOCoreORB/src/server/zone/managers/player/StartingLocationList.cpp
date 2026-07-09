#include "StartingLocationList.h"

StartingLocationList::StartingLocationList() : SortedVector<StartingLocation>() {
}

int StartingLocationList::getTotalLocations() {
	return size();
}

void StartingLocationList::parseFromIffStream(IffStream* iffStream) {
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

void StartingLocationList::insertToMessage(Message* msg) {
	msg->insertInt(size());

	for (int i = 0; i < size(); ++i)
		get(i).insertToMessage(msg);
}