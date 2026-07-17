/*
 * MeshData.h
 *
 *  Created on: 04/22/2016
 *      Author: gslomin
 */

#pragma once

#include "engine/engine.h"

namespace templates {
namespace appearance {

class MeshTriangle {
protected:
	int verts[3];

public:
	MeshTriangle();

	MeshTriangle(int a, int b, int c);

	MeshTriangle(const MeshTriangle& mesh);

	MeshTriangle& operator=(const MeshTriangle& mesh);

	const int* getVerts() const;

	const int* getVerts();

	void set(uint8 index, uint32 value);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	friend class MeshData;

	friend class MeshAppearanceTemplate;
};

class MeshData : public Object {
protected:
	Vector <Vector3> vertices;
	Vector <MeshTriangle> triangles;

public:
	MeshData();

	MeshData(const MeshData& data);

	void readObject(IffStream* iffStream);

	Vector<Vector3>* getVerts();

	const Vector<Vector3>* getVerts() const;

	Vector<MeshTriangle>* getTriangles();

	static Reference<MeshData*> makeCopyNegateZ(const MeshData* mesh, const Matrix4& parentTransform);

	void transformMeshData(const Matrix4& transform);

	Vector <MeshTriangle>* getMeshWithinBounds(AABB& bounds) const;

	AABB buildAABB() const;

	const Vector<MeshTriangle>* getTriangles() const;

	friend class MeshAppearanceTemplate;

};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
