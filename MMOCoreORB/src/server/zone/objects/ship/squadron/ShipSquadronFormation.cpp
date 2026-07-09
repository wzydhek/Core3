#include "ShipSquadronFormation.h"

Vector3 ShipSquadronFormation::getPosition(int type, int index, float radius, int size) {
	if (index <= 0) {
		return Vector3::ZERO;
	}

	switch (type) {
		case Type::LINE: {
			return getFormationLine(index, radius);
		}
		case Type::WALL: {
			return getFormationWall(index, radius);
		}
		case Type::WEDGE: {
			return getFormationWedge(index, radius);
		}
		default: {
			return Vector3::ZERO;
		}
	}
}

Vector3 ShipSquadronFormation::getFormationLine(int index, float radius) {
	int step = (index + 1) / 2;
	float x = step * radius;

	if (index % 2 == 1) {
		x = -x;
	}

	return Vector3(x, 0.f, 0.f);
}

Vector3 ShipSquadronFormation::getFormationWall(int index, float radius, int size) {
	int columns = 5; // sqrtf(size);
	int rows = 5;	 // size / columns;

	int col = index % columns;
	int stepX = (col + 1) / 2;
	float x = stepX * radius;

	if (col % 2 == 1) {
		x = -x;
	}

	int row = (index / columns) % rows;
	int stepY = (row + 1) / 2;
	float y = stepY * radius;

	if (row % 2 == 1) {
		y = -y;
	}

	int layer = index / (rows * columns);
	int stepZ = (layer + 1) / 2;
	float z = stepZ * radius;

	if (layer % 2 == 1) {
		z = -z;
	}

	return Vector3(x, y, z);
}

Vector3 ShipSquadronFormation::getFormationWedge(int index, float radius) {
	int step = (index + 1) / 2;
	float x = step * radius;
	float z = -step * radius;

	if (index % 2 == 1) {
		x = -x;
	}

	return Vector3(x, 0.f, z);
}