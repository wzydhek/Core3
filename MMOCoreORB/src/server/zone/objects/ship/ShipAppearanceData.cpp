#include "ShipAppearanceData.h"
#include "templates/datatables/DataTableRow.h"

ShipAppearanceData::ShipAppearanceData(const String& chassisName) {
	dataName = chassisName;

	readChassisIff();
}

void ShipAppearanceData::readChassisIff() {
	IffStream* iffStream = DataArchiveStore::instance()->openIffFile("datatables/space/ship_chassis_" + dataName + ".iff");
	if (iffStream == nullptr) {
		return;
	}

	DataTableIff dataTable;
	dataTable.readObject(iffStream);

	for (int i = 0; i < dataTable.getTotalRows(); ++i) {
		DataTableRow* row = dataTable.getRow(i);
		if (row == nullptr || row->getCellsSize() == 0) {
			break;
		}

		int slot = -1;
		String key;
		String value;

		for (int i = 0; i < row->getCellsSize(); ++i) {
			auto cell = row->getCell(i);
			if (cell == nullptr || cell->toString() == "") {
				continue;
			}

			if (i == 0) {
				key = cell->toString();
			} else {
				slot = i - 1;
				value = cell->toString();
				break;
			}
		}

		if (slot != -1 && key != "" && value != "") {
			if (defaultMap.get(slot) == "" && !value.contains("_s02")) {
				defaultMap.put(slot, key);
			}

			if (advancedMap.get(slot) == "" && value.contains("_s02")) {
				advancedMap.put(slot, key);
			}

			appearanceMap.put(key, value);
		}
	}

	delete iffStream;
}

const String& ShipAppearanceData::getDefaultAppearance(uint32 slot) const {
	return defaultMap.get(slot);
}

const String& ShipAppearanceData::getAdvancedAppearance(uint32 slot) const {
	return advancedMap.get(slot);
}

bool ShipAppearanceData::contains(const String& dataName) const {
	return appearanceMap.get(dataName) != "";
}

int ShipAppearanceData::size() const {
	return appearanceMap.size();
}