/*
 * FloorMesh.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "templates/IffTemplate.h"
#include "templates/appearance/PathNode.h"
#include "templates/appearance/PathGraph.h"

//#define RENDER_EXTERNAL_FLOOR_MESHES_ONLY

class MeshData;

class EdgeID {
	int triangleID;
	int edgeID;
public:
	EdgeID(int triangleID, int edgeID);

	EdgeID();

	EdgeID(const EdgeID& edge) = default;
	EdgeID& operator=(const EdgeID& edge) = default;

	inline int getEdgeID() const { return edgeID; }
	inline int getTriangleID() const { return triangleID; }

	int compareTo(const EdgeID& rhs) const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

};

class Nods {
	float x0, y0, z0, x1, y1, z1;
	int id, var2, leftNode, rightNode;

public:
	Nods();

	void readObject(IffStream* iffStream);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

};

class Bedg {
	int triangleID;
	int edgeID;
	char var3;
public:
	Bedg();

	void readObject(IffStream* iffStream);

	int getTriangleID() const;

	int getEdgeID() const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

class FloorMeshTriangleNode : public TriangleNode {
public:
	class Edge : public Object {
	protected:
		int32 neighbor;
		uint8 flags;
		int32 portalID;
	public:
		Edge();

		int32 getNeighbor() const { return neighbor; }

		uint8 getFlags() const { return flags; }

		int32 getPortalID() const { return portalID; }
		friend class FloorMeshTriangleNode;
		friend class FloorMesh;
	};

protected:

	int32 indicies[3];
	uint32 triangleID;
	Vector3 normal;
	Edge edges[3];
	bool nonSolid;
	int32 tag;
	FloorMesh *mesh;
	Vector<TriangleNode*> neighbors;

public:
	FloorMeshTriangleNode(FloorMesh* floorMesh);

	void readObject(IffStream* iffStream);

	int getIndex(int val);

	bool isEdge() const;

	uint32 getID() const final;

	const Edge* getEdges() const;

	void addNeighbor(TriangleNode* node);

	const Vector<TriangleNode*>* getNeighbors() const final;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	friend class FloorMesh;
};

class FloorMesh : public IffTemplate, public Logger {
	Vector<Vector3> vertices;
	Vector<FloorMeshTriangleNode*> tris;
	SortedVector<EdgeID> connectedEdges;
	SortedVector<EdgeID> uncrossableEdges;
	SortedVector<EdgeID> blockingEdges;

	PathGraph* pathGraph;
	AABBTree* aabbTree;

	int cellID;

public:
	FloorMesh();
	~FloorMesh();

	void readObject(IffStream* iffStream);
	void parseBTRE(IffStream* iffStream);
	void parseBEDG(IffStream* iffStream);
	void parsePGRF(IffStream* iffStream);
	void parseVersion0006(IffStream* iffStream);
	void parseVersion0005(IffStream* iffStream);
	void parseVersion0003(IffStream* iffStream);

	Vector <Reference<MeshData*>> getTransformedMeshData(const Matrix4& parentTransform) const;

	const Vector<TriangleNode*>* getNeighbors(uint32 triangleID) const;

	const TriangleNode* findNearestTriangle(const Vector3& point) const;

	bool testCollide(float x, float z, float y, float radius) const;

	const PathNode* getGlobalNode(int globalID) const;

	const PathGraph* getPathGraph() const;

	PathGraph* getPathGraph();

	const FloorMeshTriangleNode* getTriangle(int tri) const;

	int getTriangleCount() const;

	const AABBTree* getAABBTree() const;

	const Vector3* getVertex(int vert) const;

	int getCellID() const;

	void setCellID(int id);

	float calculateManhattanDistance(const TriangleNode* node1, const TriangleNode* node2) const;

	friend class FloorMeshTriangleNode;
};
