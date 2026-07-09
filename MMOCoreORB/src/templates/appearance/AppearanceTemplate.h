/*
 * AppearanceTemplate.h
 *
 *  Created on: 11/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/collision/BoundingVolumeFactory.h"
#include "templates/appearance/MeshData.h"

class AppearanceTemplate : public Object {
	String floorName;
	String fileName;
	BaseBoundingVolume* volume = nullptr;
	BaseBoundingVolume* collisionVolume = nullptr;
	VectorMap<String, Matrix4> hardpoints;
public:

	virtual uint32 getType() const;

	const String& getFloorMesh() const;

	const BaseBoundingVolume* getBoundingVolume() const;

	const VectorMap<String, Matrix4>& getHardpoints() const;

	const BaseBoundingVolume* getCollisionVolume() const;

	const String& getFileName() const;

	virtual bool testCollide(const Sphere& testsphere) const = 0;

	/**
	 * Checks for intersection against ray, stops on any intersection
	 * @return intersectionDistance, triangle which it intersects
	 */
	virtual bool intersects(const Ray& ray, float distance, float& intersectionDistance, Triangle*& triangle,
							bool checkPrimitives = false) const = 0;

	/**
	 * Checks for all intersections
	 */
	virtual int intersects(const Ray& ray, float maxDistance, SortedVector <IntersectionResult>& result) const = 0;


	virtual void readObject(IffStream* iffStream);

	virtual ~AppearanceTemplate();

	virtual Vector <Reference<MeshData*>> getTransformedMeshData(const Matrix4& parentTransform) const = 0;
};
