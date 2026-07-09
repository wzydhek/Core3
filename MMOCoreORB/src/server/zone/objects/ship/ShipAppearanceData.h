#pragma once

#include "engine/engine.h"
#include "templates/manager/DataArchiveStore.h"
#include "templates/datatables/DataTableIff.h"
#include "server/zone/objects/ship/ComponentSlots.h"

class DataTableRow;

class ShipAppearanceData : public Object {
protected:
	HashTable<String, String> appearanceMap;
	HashTable<uint32, String> advancedMap;
	HashTable<uint32, String> defaultMap;

	String dataName;

public:
	ShipAppearanceData(const String& chassisName);

	void readChassisIff();

	const String& getDefaultAppearance(uint32 slot) const;

	const String& getAdvancedAppearance(uint32 slot) const;

	bool contains(const String& dataName) const;

	int size() const;
};
