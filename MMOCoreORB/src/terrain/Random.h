/*
 * Random.h
 *
 *  Created on: 17/12/2010
 *      Author: victor
 */

#pragma once

namespace trn {
namespace ptat {

class Random {
	int seed;
	int unknown;

	int table[322];

public:
	Random();

	void setSeed(int seed);

	int next();
};

}
}

using namespace trn::ptat;
