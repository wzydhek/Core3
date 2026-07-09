#include "CreatureState.h"

void CreatureState::loadStateData() {
	UniqueReference<IffStream*> iffStream(TemplateManager::instance()->openIffFile("datatables/include/state.iff"));

	if (iffStream == nullptr) {
		error("Could not load states.");
		return;
	}

	DataTableIff dtiff;
	dtiff.readObject(iffStream);

	states.removeAll();

	for (int i = 0; i < dtiff.getTotalRows(); i++) {
		DataTableRow* row = dtiff.getRow(i);
		String name;
		int value;

		row->getValue(0, name);
		row->getValue(1, value);

		if (value >= 0)
			states.put(name.toLowerCase(), 1ull << value);
		else
			states.put(name.toLowerCase(), 0x00);
	}
}

uint64 CreatureState::getState(const String& state) const {
	return states.get(state.toLowerCase());
}

String CreatureState::getSpecialName(const uint64 state, bool initialCap) const {
	// This method is used for String building to match up with the tre's
	String name = "";

	switch (state) {
		case POISONED:
			name = "poison";
			break;
		case DISEASED:
			name = "disease";
			break;
		case ONFIRE:
			name = "fire";
			break;
	}

	if (initialCap)
		name[0] = toupper(name[0]);

	return name;
}

String CreatureState::getName(const uint64 state, bool initialCap) const {
	String name = "invalid";

	HashTableIterator<String, uint64> iter(&states);
	iter.resetIterator();

	while (iter.hasNext()) {
		uint64 testState;

		iter.getNextKeyAndValue(name, testState);

		if (testState == state)
			break;
	}

	if (initialCap)
		name[0] = toupper(name[0]);

	return name;
}