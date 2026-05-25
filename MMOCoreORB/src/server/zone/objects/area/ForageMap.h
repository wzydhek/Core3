/*
 * ForageMap.h
 *
 *  Created on: 2/24/2011
 *      Author: Anakis
 */

#pragma once

#include "engine/engine.h"
#include "ForageAreaCollection.h"

class ForageMap : public VectorMap<String, Reference<ForageAreaCollection*> > {

};
