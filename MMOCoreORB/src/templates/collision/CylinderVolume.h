/*
 * CylinderVolume.h
 *
 *      Author: gslomin
 */

#pragma once

#include "BaseBoundingVolume.h"

namespace templates {
namespace collision {

class CylinderVolume : public BaseBoundingVolume {
protected:
	AABB bbox;
public:
	Sphere base;
	float height;

	CylinderVolume();

	virtual const AABB& getBoundingBox() const;

	virtual void read(IffStream *iff);

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
