/*
 * MeshData.h
 *
 *  Created on: 04/22/2016
 *      Author: gslomin
 */

#include "MeshData.h"

MeshTriangle::MeshTriangle() {
	verts[0] = 0;
	verts[1] = 1;
	verts[2] = 2;
}

MeshTriangle::MeshTriangle(int a, int b, int c) {
	verts[0] = a;
	verts[1] = b;
	verts[2] = c;
}

MeshTriangle::MeshTriangle(const MeshTriangle& mesh) {
	verts[0] = mesh.verts[0];
	verts[1] = mesh.verts[1];
	verts[2] = mesh.verts[2];
}

MeshTriangle& MeshTriangle::operator=(const MeshTriangle& mesh) {
	if (this == &mesh) {
		return *this;
	}

	verts[0] = mesh.verts[0];
	verts[1] = mesh.verts[1];
	verts[2] = mesh.verts[2];

	return *this;
}

const int* MeshTriangle::getVerts() const {
	return verts;
}

const int* MeshTriangle::getVerts() {
	return verts;
}

void MeshTriangle::set(uint8 index, uint32 value) {
	verts[index] = value;
}

bool MeshTriangle::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

bool MeshTriangle::parseFromBinaryStream(ObjectInputStream* stream) {
	return false;
}

MeshData::MeshData() {
}

MeshData::MeshData(const MeshData& data) : Object() {
	vertices = data.vertices;
	triangles = data.triangles;
}

AABB MeshData::buildAABB() const {
	float minx = 100000;
	float miny = 100000;
	float minz = 100000;

	float maxx = -1000000;
	float maxy = -1000000;
	float maxz = -1000000;

	for (int i = 0; i < vertices.size(); i++) {
		const Vector3& vert = vertices.getUnsafe(i);
		const float x = vert.getX();
		const float y = vert.getY();
		const float z = vert.getZ();

		if (x < minx)
			minx = x;

		if (y < miny)
			miny = y;

		if (z < minz)
			minz = z;

		if (x > maxx)
			maxx = x;

		if (y > maxy)
			maxy = y;

		if (z > maxz)
			maxz = z;
	}

	return AABB(Vector3(minx, miny, minz), Vector3(maxx, maxy, maxz));
}

Vector <MeshTriangle>* MeshData::getMeshWithinBounds(AABB& bounds) const {
	float bminx = bounds.getXMin();
	float bminy = bounds.getYMin();
	float bminz = bounds.getZMin();

	float bmaxx = bounds.getXMax();
	float bmaxy = bounds.getYMax();
	float bmaxz = bounds.getZMax();

	Vector <MeshTriangle>* tris = new Vector<MeshTriangle>();

	for (int i = 0; i < triangles.size(); i++) {
		const MeshTriangle& tri = triangles.getUnsafe(i);
		const int* v = tri.getVerts();
		float minx = 30000;
		float miny = 30000;
		float minz = 30000;

		float maxx = -30000;
		float maxy = -30000;
		float maxz = -30000;

		for (int i = 0; i < 3; i++) {
			const Vector3& vert = vertices.get(v[i]);
			const float x = vert.getX();
			const float y = vert.getY();
			const float z = vert.getZ();

			if (x > maxx)
				maxx = x;

			if (y > maxy)
				maxy = y;

			if (z > maxz)
				maxz = z;

			if (x < minx)
				minx = x;

			if (y < miny)
				miny = y;

			if (z < minz)
				minz = z;
		}
		if (maxx >= bminx && minx <= bmaxx && maxy >= bminy && miny <= bmaxy && maxz >= bminz && minz <= bmaxz)
			tris->add(tri);
	}

	return tris;
}

void MeshData::readObject(IffStream* iffStream) {
	iffStream->openForm('VTXA');
	iffStream->openForm('0003');
	iffStream->openChunk('INFO');

	iffStream->getInt(); //unk

	int numVertices = iffStream->getInt();

	iffStream->closeChunk();

	Chunk* vertexDataChunk = iffStream->openChunk('DATA');

	int vertexDataChunkSize = vertexDataChunk->getChunkSize();

	int intBytesPerVertex = vertexDataChunkSize / numVertices;

	vertices.removeAll(numVertices);

	for (int i = 0; i < numVertices; ++i) {
		vertices.emplace(iffStream->getVector3());

		vertexDataChunk->shiftOffset(intBytesPerVertex - 12);
	}

	iffStream->closeChunk('DATA');
	iffStream->closeForm('0003');
	iffStream->closeForm('VTXA');

	Chunk* indexData = iffStream->openChunk('INDX');

	int indexCount = iffStream->getInt();

	triangles.removeAll(indexCount / 3);

	for (int i = 1; i <= indexCount; i += 3) {
		int a = indexData->readShort();
		int b = indexData->readShort();
		int c = indexData->readShort();

		MeshTriangle triangle;
		triangle.verts[0] = a;
		triangle.verts[1] = b;
		triangle.verts[2] = c;

		triangles.add(triangle);
	}

	iffStream->closeChunk();
}

Vector<Vector3>* MeshData::getVerts() {
	return &vertices;
}

const Vector<Vector3>* MeshData::getVerts() const {
	return &vertices;
}

Vector<MeshTriangle>* MeshData::getTriangles() {
	return &triangles;
}

Reference<MeshData*> MeshData::makeCopyNegateZ(const MeshData* mesh, const Matrix4& parentTransform) {
	Reference<MeshData*> newData = new MeshData(*mesh);
	for (auto& vert : newData->vertices) {
		vert.setZ(-vert.getZ());
		vert = vert * parentTransform;
	}
	return newData;
}

void MeshData::transformMeshData(const Matrix4& transform) {
	for (int i = 0; i < vertices.size(); i++) {
		Vector3& vert = vertices.get(i);
		vert = Vector3(vert.getX(), vert.getY(), vert.getZ()) * transform;
	}
}

const Vector<MeshTriangle>* MeshData::getTriangles() const {
	return &triangles;
}