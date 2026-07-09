/*
 * PathGraph.cpp
 *
 *  Created on: 03/12/2010
 *      Author: victor
 */

#include "PathGraph.h"
#include "templates/appearance/FloorMesh.h"

PathGraph::PathGraph(FloorMesh* floor) {
	floorMesh = floor;
	type = None;
}

PathGraph::~PathGraph() {
	pathNodes.forEach([](auto node) { delete node; });
}

uint32 PathNode::getID() const {
	int cellID = pathGraph->getFloorMesh()->getCellID();

	return (cellID << 16) + id;
}

void PathGraph::readObject(IffStream* iffStream) {
	iffStream->openForm('PGRF');
	iffStream->openForm('0001');
	iffStream->openChunk('META');

	type = static_cast<PathGraphType>(iffStream->getInt());

	iffStream->closeChunk('META');

	iffStream->openChunk('PNOD');

	int nodesSize = iffStream->getInt();

	pathNodes.removeAll(nodesSize);

	for (int i = 0; i < nodesSize; ++i) {
		PathNode* pathNode = new PathNode(this);

		pathNode->readObject(iffStream);

		pathNodes.add(pathNode);
	}

	iffStream->closeChunk('PNOD');

	iffStream->openChunk('PEDG');

	int pathEdgeSize = iffStream->getInt();

	pathEdges.removeAll(pathEdgeSize);

	for (int i = 0; i < pathEdgeSize; ++i) {
		PathEdge pathEdge;

		pathEdge.readObject(iffStream);

		pathEdges.add(pathEdge);
	}

	iffStream->closeChunk('PEDG');

	iffStream->openChunk('ECNT');

	int ecntSize = iffStream->getInt();

	edgeCounts.removeAll(ecntSize);

	for (int i = 0; i < ecntSize; ++i) {
		edgeCounts.add(iffStream->getInt());
	}

	iffStream->closeChunk('ECNT');

	iffStream->openChunk('ESTR');

	int estrSize = iffStream->getInt();

	edgeStarts.removeAll(estrSize);

	for (int i = 0; i < estrSize; ++i) {
		edgeStarts.add(iffStream->getInt());
	}

	iffStream->closeChunk('ESTR');
	iffStream->closeForm('0001');
	iffStream->closeForm('PGRF');

	connectNodes(pathEdges);
}

float PathGraph::calculateManhattanDistance(const PathNode* node1, const PathNode* node2) {
	/*return abs(node1->getX() - node2->getX()) + abs(node1->getY() - node2->getY())
			+ abs(node1->getZ() - node2->getZ());*/

	return node1->getPosition().squaredDistanceTo(node2->getPosition());
}

const PathNode* PathGraph::getNode(int globalNumberID) const {
	for (int i = 0; i < pathNodes.size(); ++i) {
		const PathNode* pathNode = pathNodes.getUnsafe(i);

		if (pathNode->getGlobalGraphNodeID() == globalNumberID)
			return pathNode;
	}

	return nullptr;
}

const PathNode* PathGraph::findNearestNode(float x, float z, float y) const {
	return findNearestNode(Vector3(x, y, z));
}

const PathNode* PathGraph::findGlobalNode(int globalNodeID) const {
	for (int i = 0; i < pathNodes.size(); ++i) {
		const PathNode* pathNode = pathNodes.getUnsafe(i);

		if (pathNode->getGlobalGraphNodeID() == globalNodeID)
			return pathNode;
	}

	return nullptr;
}

const PathNode* PathGraph::findNearestGlobalNode(const Vector3& pointAlfa) const {
	float minDistance = 160000000.f;
	const PathNode* node = nullptr;

	for (int i = 0; i < pathNodes.size(); ++i) {
		const PathNode* pathNode = pathNodes.getUnsafe(i);

		if (pathNode->getGlobalGraphNodeID() == -1)
			continue;

		Vector3 point(pathNode->getX(), pathNode->getY(), pathNode->getZ());

		float sqrDistance = pointAlfa.squaredDistanceTo(point);

		if (sqrDistance < minDistance) {
			minDistance = sqrDistance;
			node = pathNode;
		}
	}

	return node;
}

Vector<const PathNode*> PathGraph::getEntrances() const {
	Vector<const PathNode*> vec;
	for (const PathNode *node : pathNodes) {
		if(node->getType() == PathNode::BuildingEntrance) {
			vec.add(node);
		}
	}
	return vec;
}

const PathNode* PathGraph::findNearestNode(const Vector3& pointAlfa) const {
	float minDistance = 160000000.f;
	PathNode* node = nullptr;

	for (int i = 0; i < pathNodes.size(); ++i) {
		PathNode* pathNode = pathNodes.getUnsafe(i);

		Vector3 point(pathNode->getX(), pathNode->getY(), pathNode->getZ());

		float sqrDistance = pointAlfa.squaredDistanceTo(point);

		if (sqrDistance < minDistance) {
			minDistance = sqrDistance;
			node = pathNode;
		}
	}

	return node;
}

void PathGraph::connectNodes(Vector<PathEdge>& pathEdges) {
	for (int i = 0; i < pathEdges.size(); ++i) {
		PathEdge* pathEdge = &pathEdges.get(i);

		int from = pathEdge->getFromConnection();
		int to = pathEdge->getToConnection();

		PathNode* fromNode = pathNodes.get(from);
		PathNode* toNode = pathNodes.get(to);

		/*Vector<PathNode*>* path = AStarAlgorithm<PathGraph, PathNode>::search<uint32>(this, fromNode, toNode);

		if (path != nullptr) {
			System::out << "found path\n";
			delete path;
		} else {
			System::out << "didint find path\n";
		}*/

		fromNode->addChild(toNode);
	}
}

void PathGraph::addPathNode(PathNode* pathNode) {
	pathNodes.add(pathNode);
}

const Vector<PathEdge>* PathGraph::getPathEdges() const {
	return &pathEdges;
}

const Vector<PathNode*>* PathGraph::getPathNodes() const {
	return &pathNodes;
}

Vector<const PathNode*> PathGraph::getGlobalNodes() const {
	Vector<const PathNode*> nodes;

	for (int i = 0; i < pathNodes.size(); ++i) {
		if (pathNodes.get(i)->getGlobalGraphNodeID() != -1)
			nodes.add(pathNodes.get(i));
	}

	return nodes;
}

Vector<PathNode*> PathGraph::getGlobalNodes() {
	Vector<PathNode*> nodes;

	for (int i = 0; i < pathNodes.size(); ++i) {
		if (pathNodes.get(i)->getGlobalGraphNodeID() != -1)
			nodes.add(pathNodes.get(i));
	}

	return nodes;
}

const FloorMesh* PathGraph::getFloorMesh() const {
	return floorMesh;
}

PathGraph::PathGraphType PathGraph::getType() const {
	return type;
}