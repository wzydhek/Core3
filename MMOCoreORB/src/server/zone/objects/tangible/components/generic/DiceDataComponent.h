/*
 * DataObjectComponent.h
 *
 *  Created on: 18/03/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class DiceDataComponent : public DataObjectComponent {
protected:
	byte sides;
public:
	DiceDataComponent();

	virtual ~DiceDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void setSides(byte count);

	byte getSides() const;

	bool isDiceData();

private:
	void addSerializableVariables();
};
