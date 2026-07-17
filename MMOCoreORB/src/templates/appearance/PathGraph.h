/*
 * PathGraph.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/appearance/PathNode.h"
#include "templates/IffTemplate.h"

namespace templates {
namespace appearance {

class FloorMesh;

class PathGraph : public IffTemplate {
	enum PathGraphType
	{
		Cell,
		Building,
		City,

		None,
	};


	Vector<PathNode*> pathNodes;
	Vector<PathEdge> pathEdges;

	PathGraphType type;

	Vector<int> edgeCounts;
	Vector<int> edgeStarts;

	FloorMesh* floorMesh;

protected:
	void connectNodes(Vector<PathEdge>& pathEdges);

public:
	PathGraph(FloorMesh* floor);

	~PathGraph();

	void readObject(IffStream* iffStream);

	static float calculateManhattanDistance(const PathNode* node1, const PathNode* node2);

	const PathNode* getNode(int globalNumberID) const;

	const PathNode* findNearestNode(float x, float z, float y) const;

	const PathNode* findNearestNode(const Vector3& pointAlfa) const;
	Vector<const PathNode*> getEntrances() const;
	const PathNode* findNearestGlobalNode(const Vector3& pointAlfa) const;
	const PathNode* findGlobalNode(int globalNodeID) const;

	void addPathNode(PathNode* pathNode);

	const Vector<PathEdge>* getPathEdges() const;

	const Vector<PathNode*>* getPathNodes() const;

	Vector<const PathNode*> getGlobalNodes() const;

	Vector<PathNode*> getGlobalNodes();

	const FloorMesh* getFloorMesh() const;

	PathGraphType getType() const;

};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
