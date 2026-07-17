/*
 * BoxVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "BaseBoundingVolume.h"

namespace templates {
namespace collision {

class BoxVolume : public BaseBoundingVolume {
protected:
	AABB bbox;
public:
	BoxVolume();

	const AABB& getBoundingBox() const;

	void read(IffStream *iff);

	bool isBoundingBox() const;

#ifdef OSG_RENDERER
	osg::ref_ptr<osg::Node> draw() const;
#endif

};

} // namespace collision
} // namespace templates

using namespace templates::collision;
