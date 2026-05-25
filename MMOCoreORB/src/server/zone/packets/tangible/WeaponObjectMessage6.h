/*
 * WeaponObjectMEssage6.h
 *
 *  Created on: 01/05/2012
 *      Author: victor
 */

#pragma once

#include "TangibleObjectMessage6.h"

class WeaponObjectMessage6 : public TangibleObjectMessage6 {
public:
	WeaponObjectMessage6(TangibleObject* tano)
			: TangibleObjectMessage6(tano, 0x5745414F) {

		setSize();
	}

};
