/*
 * MeshAppearanceTemplate.h
 *
 *  Created on: 07/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/appearance/AppearanceTemplate.h"
#include "templates/appearance/MeshData.h"

namespace templates {
namespace appearance {

class MeshAppearanceTemplate : public AppearanceTemplate {
	Vector<Reference<MeshData*> > meshes;
	//Vector<Triangle> triangles;

	AABBTree* aabbTree;
	Sphere* boundingSphere;
	//String file;

public:
	virtual uint32 getType() const;

	MeshAppearanceTemplate();

	~MeshAppearanceTemplate();

	void createAABB();

	void readObject(IffStream* templateData);

	void parse(IffStream* iffStream);
	void parseSPS(IffStream* iffStream);
	void parseVertexData(IffStream* iffStream, int idx);

	bool testCollide(float x, float z, float y, float radius) const;

	void getTriangles(Vector<Triangle*>& triangles) const;

	const AABBTree* getAABBTree() const;

	const Sphere* getBoundingSphere() const;

	const Vector<Reference<MeshData*>>& getMeshes() const;

	virtual bool testCollide(const Sphere& testsphere) const;

	/**
	 * Checks for intersection against ray, stops on any intersection
	 * @return intersectionDistance, triangle which it intersects
	 */
	virtual bool intersects(const Ray& ray, float distance, float& intersectionDistance, Triangle*& triangle, bool checkPrimitives = false) const;

	/**
	 * Checks for all intersections
	 */
	virtual int intersects(const Ray& ray, float maxDistance, SortedVector<IntersectionResult>& result) const;

	virtual Vector<Reference<MeshData*>> getTransformedMeshData(const Matrix4& parentTransform) const;
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
