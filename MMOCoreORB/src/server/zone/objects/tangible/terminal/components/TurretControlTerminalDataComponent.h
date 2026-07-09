/*
 * TurretControlTerminalDataComponent.h
 *
 *  Created on: Jan 27, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class TurretControlTerminalDataComponent : public DataObjectComponent {
protected:
	int turretIndex;
	unsigned int suiBoxID;

public:
	TurretControlTerminalDataComponent();

	virtual ~TurretControlTerminalDataComponent();

	void writeJSON(nlohmann::json& j) const;

	bool isTurretControlTerminalData();

	int getTurrteIndex() const;

	void setTurretIndex(int indx);

	void setSuiBoxID(unsigned int id);

	unsigned int getSuiBoxID() const;


private:
	void addSerializableVariables();
};
