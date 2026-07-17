/*
 * SphereVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "BaseBoundingVolume.h"

namespace templates {
namespace collision {

class SphereVolume : public BaseBoundingVolume {
protected:
	AABB bbox;
public:
	SphereVolume();

	const AABB& getBoundingBox() const;

	bool isBoundingSphere() const;

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
