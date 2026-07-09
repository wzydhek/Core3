/*
 * IntVectorDeltaVector.h
 *
 *  Created on: Feb 24, 2012
 *      Author: kyle
 */

#pragma once

#include "server/zone/objects/scene/variables/DeltaVector.h"

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {
namespace variables {

class IntVectorDeltaVector: public DeltaVector<Vector<int> > {
public:
	IntVectorDeltaVector();
	
	~IntVectorDeltaVector();
};

}
}
}
}
}

using namespace server::zone::objects::manufactureschematic::variables;
