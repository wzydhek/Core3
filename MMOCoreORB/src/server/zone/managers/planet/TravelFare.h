/*
 * TravelFare.h
 *
 *  Created on: April 9, 2012
 *      Author: Itac
 */

#pragma once

#include "system/util/VectorMap.h"
#include "system/lang/String.h"

class TravelFare : public VectorMap<String, VectorMap<String, int> > {

};
