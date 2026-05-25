/*
 * DroidLabratory.h
 *
 *  Created on: Aug 20, 2014
 *      Author: swgemu
 */

#pragma once

#include "ResourceLabratory.h"

namespace server {
namespace zone {
namespace managers {
namespace crafting {
namespace labratories {

class DroidLabratory: public ResourceLabratory {
public:
	DroidLabratory();
	virtual ~DroidLabratory();
	int getCreationCount(ManufactureSchematic* manufactureSchematic);
};

}
}
}
}
}

using namespace server::zone::managers::crafting::labratories;
