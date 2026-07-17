/*
 * PathNode.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "engine/util/u3d/Vector3.h"
#include "templates/appearance/PathEdge.h"

namespace templates {
namespace appearance {

class PathGraph;

class PathNode {
public:
	enum PathNodeType
	{
		CellPortal           = 0,
		CellWaypoint         = 1,
		CellPOI              = 2,

		BuildingEntrance     = 3,
		BuildingCell         = 4,
		BuildingPortal       = 5,

		CityBuildingEntrance = 6,
		CityWaypoint         = 7,
		CityPOI              = 8,
		CityBuilding         = 9,
		CityEntrance         = 10,

		BuildingCellPart     = 11,

		Invalid              = 12,
	};
protected:

	Vector<PathNode*> children;

	uint32 id;
	int var2, globalGraphNodeID;
	PathNodeType type;
	float x, z, y, radius;

	PathGraph* pathGraph;

public:
	PathNode(PathGraph* graph);

	void addChild(PathNode* node);

	void readObject(IffStream* iffStream);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	float getX() const;

	float getY() const;

	float getZ() const;

	uint32 getID() const;

	Vector3 getPosition() const;

	float getRadius() const;

	PathNodeType getType() const;

	const Vector<PathNode*>* getNeighbors() const;

	int getGlobalGraphNodeID() const;

	const PathGraph* getPathGraph() const;

	static String typeToString(PathNodeType nodeType);

	String toString() const;

	String toStringData() const;
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
