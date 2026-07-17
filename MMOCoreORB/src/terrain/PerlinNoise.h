/*
 * PerlinNoise.h
 *
 *  Created on: 17/12/2010
 *      Author: victor
 */

#pragma once

#include "system/platform.h"

/* coherent noise function over 1, 2 or 3 dimensions */
/* (copyright Ken Perlin) */

#define B 0x100

#include "Random.h"
#include <cmath>

namespace terrain {

class PerlinNoise {
	int p[B + B + 2];
	//float g3[B + B + 2][3];
	float g2[B + B + 2][2];
	float g1[B + B + 2];

	int start;

	trn::ptat::Random* rand;

/*
#define setup(i,b0,b1,r0,r1)\
		t = (double)vec[i] + (double)N;\
		b0 = ((int)t) & BM;\
		b1 = (b0+1) & BM;\
		r0 = t - (int)t;\
		r1 = r0 - 1.;
*/

public:
	PerlinNoise(trn::ptat::Random* r);

	float noise1(double arg) const;

	float noise2(double vec[2]) const;

	static void normalize2(float v[2]);

	static void normalize3(float v[3]);

	void init();

};

} // namespace terrain

using namespace terrain;