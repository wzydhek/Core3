#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {

class TerminalSpawn : public Object {

protected:
	Vector3 spawnLoc;
	int cellID;
	String templateName;
	Quaternion rotation;

public:
	TerminalSpawn(String name, Vector3 loc, int cell, Quaternion rot);

	~TerminalSpawn();

	String getTemplateName();

	int getCellID();

	Vector3* getSpawnLoc();

	Quaternion getRotation() const;

};

}
}
}
}

using namespace server::zone::managers::gcw;
