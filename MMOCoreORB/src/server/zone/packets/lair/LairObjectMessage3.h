/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/tangible/LairObject.h"

//class LairObject;

class LairObjectMessage3 : public TangibleObjectMessage3 {
public:
	LairObjectMessage3(LairObject* tano);
};
