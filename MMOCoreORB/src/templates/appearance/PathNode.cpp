#include "PathNode.h"

PathNode::PathNode(PathGraph* graph) {
	pathGraph = graph;
	id = 0;
	var2 = globalGraphNodeID = 0;
	type = Invalid;
	x = z = y = radius = 0;
}

void PathNode::addChild(PathNode* node) {
	children.add(node);
}

void PathNode::readObject(IffStream* iffStream) {
	id = iffStream->getInt();							   // index
	var2 = iffStream->getInt();							   // ID
	globalGraphNodeID = iffStream->getInt();			   // Key
	type = static_cast<PathNodeType>(iffStream->getInt()); // type

	x = iffStream->getFloat(); // position
	z = iffStream->getFloat();
	y = iffStream->getFloat();
	radius = iffStream->getFloat(); // radius
	if (radius == 0.0f)
		radius = 0.5f;
}

bool PathNode::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

bool PathNode::parseFromBinaryStream(ObjectInputStream* stream) {
	return false;
}

float PathNode::getX() const {
	return x;
}

float PathNode::getY() const {
	return y;
}

float PathNode::getZ() const {
	return z;
}

Vector3 PathNode::getPosition() const {
	return Vector3(x, y, z);
}

float PathNode::getRadius() const {
	return radius;
}

PathNode::PathNodeType PathNode::getType() const {
	return type;
}

const Vector<PathNode*>* PathNode::getNeighbors() const {
	return &children;
}

int PathNode::getGlobalGraphNodeID() const {
	return globalGraphNodeID;
}

const PathGraph* PathNode::getPathGraph() const {
	return pathGraph;
}

String PathNode::typeToString(PathNodeType nodeType) {
	switch (nodeType) {
		case CellPortal:
			return "CellPortal";
		case CellWaypoint:
			return "CellWaypoint";
		case CellPOI:
			return "CellPOI";
		case BuildingEntrance:
			return "BuildingEntrance";
		case BuildingCell:
			return "BuildingCell";
		case BuildingPortal:
			return "BuildingPortal";
		case CityBuildingEntrance:
			return "CityBuildingEntrance";
		case CityWaypoint:
			return "CityWaypoint";
		case CityPOI:
			return "CityPOI";
		case CityBuilding:
			return "CityBuilding";
		case CityEntrance:
			return "CityEntrance";
		case BuildingCellPart:
			return "BuildingCellPart";
		case Invalid:
			return "Invalid";
		default:
			StringBuffer buf;
			buf << "UnknownType(" << nodeType << ")";
			return buf.toString();
	}
}

String PathNode::toString() const {
	StringBuffer buf;

	buf << "PathNode(id: " << id << ", type: " << typeToString(type) << ", x: " << x << ", y: " << y << ", z: " << z << ", radius: " << radius << ", globalGraphNodeID: " << globalGraphNodeID << ")";

	return buf.toString();
}

String PathNode::toStringData() const {
	return toString();
}