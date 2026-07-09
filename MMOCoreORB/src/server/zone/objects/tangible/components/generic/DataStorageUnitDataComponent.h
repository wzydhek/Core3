/*
 * DataStorageUnitDataComponent.h
 *
 *  Created on: 11/8/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class DataStorageUnitDataComponent : public DataObjectComponent {
protected:
	byte id;
public:
	DataStorageUnitDataComponent();

	virtual ~DataStorageUnitDataComponent();

	void writeJSON(nlohmann::json& j) const;

	byte getId() const;

	bool isDataStorageUnitData();

private:
	void addSerializableVariables();
};
