/*
 * DataObjectReference.h
 *
 *  Created on: 18/03/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "DataObjectComponent.h"

class DataObjectComponentReference : public Reference<DataObjectComponent*> {
public:
	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);
	DataObjectComponent* operator=(DataObjectComponent* obj);

};

void to_json(nlohmann::json& j, const DataObjectComponentReference& ref);
