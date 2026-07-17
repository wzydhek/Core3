/*
 * DetailVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "CompositeVolume.h"

namespace templates {
namespace collision {

class DetailVolume : public CompositeVolume {
public:
	bool isDetailVolume();

	DetailVolume();

	virtual void read(IffStream *iff);

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
