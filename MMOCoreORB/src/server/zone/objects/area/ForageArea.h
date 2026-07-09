/*
 * ForageArea.h
 *
 *  Created on: 02/14/2011
 *      Author: Anakis
 */

#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

class ForageArea : public Object {

protected:

	enum {
		SIZE   = 10, //Determines the side length of the forage area 'box' (in meters).
		EXPIRE = 30  //Determines the age when each area expires (in minutes).
	};

	String planet;
	short xCoord;
	short yCoord;
	int forageType;
	Time expiration;

public:

	uint8 uses;

     ForageArea(short playerX, short playerY, const String& plt, int forageAreaType);

     int checkPermission(short playerX, short playerY, const String& playerPlanet, int forageAreaType);

};
