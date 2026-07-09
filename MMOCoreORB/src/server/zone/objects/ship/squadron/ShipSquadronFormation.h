#pragma once

#include "engine/engine.h"

class ShipSquadronFormation {
public:
	enum Type : int {
		NONE = -1,
		LINE = 0,
		WALL = 1,
		WEDGE = 2,
		SIZE,
	};

	static Vector3 getPosition(int type, int index, float radius = 1.f, int size = -1);

private:
	static Vector3 getFormationLine(int index, float radius);

	static Vector3 getFormationWall(int index, float radius, int size = 25);

	static Vector3 getFormationWedge(int index, float radius);
};
