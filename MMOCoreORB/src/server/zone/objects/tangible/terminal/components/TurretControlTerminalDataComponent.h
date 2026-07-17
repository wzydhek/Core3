/*
 * TurretControlTerminalDataComponent.h
 *
 *  Created on: Jan 27, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace components {

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

} // namespace components
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::components;
