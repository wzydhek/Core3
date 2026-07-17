/*
 * DetailAppearanceTemplate.h
 *
 *  Created on: 10/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/appearance/AppearanceTemplate.h"

namespace templates {
namespace appearance {

class DetailAppearanceTemplate : public AppearanceTemplate {
	const AppearanceTemplate* firstMesh;
public:
	virtual uint32 getType() const;

	DetailAppearanceTemplate();

	~DetailAppearanceTemplate();

	void readObject(IffStream* templateData);

	void parse(IffStream* iffStream);

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
