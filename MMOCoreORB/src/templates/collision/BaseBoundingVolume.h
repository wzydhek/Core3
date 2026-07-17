/*
 * BaseBoundingVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "engine/engine.h"

namespace templates {
namespace collision {

class BaseBoundingVolume : public Object, public Logger {
protected:
	Sphere bsphere; // All volumes have an enclosing sphere
public:
	BaseBoundingVolume() : bsphere(Vector3(0, 0, 0), 0) { }
	virtual ~BaseBoundingVolume() { }
	virtual const AABB& getBoundingBox() const = 0;

	virtual const Sphere& getBoundingSphere() const;

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const = 0;
#endif

	virtual bool isBoundingSphere() const { return false; }
	virtual bool isBoundingBox() const { return false; }
	virtual bool isCollisionMesh() const { return false; }
	virtual bool isCompositeVolume() const { return false; }
	virtual bool isComponentVolume() const { return false; }
	virtual bool isDetailVolume() const { return false; }
	
	virtual void read(IffStream *iff);
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
