/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/db/ServerDatabase.h"
#include "conf/ConfigManager.h"
#include "Galaxy.h"

#ifdef WITH_SWGREALMS_API
	#include "server/login/SWGRealmsAPI.h"
#endif

class GalaxyList {
	Vector<Galaxy> galaxies;
	Galaxy current;
	int curIdx = 0;

public:
	GalaxyList(uint32 accountid);

	bool next();

	bool isAllowed(uint32 galaxyID) const;

	uint32 getID() const;

	const String& getName() const;

	const String& getAddress() const;

	uint16 getPort() const;

	uint16 getRandomPort() const;

	uint16 getPingPort() const;

	uint32 getPopulation() const;

	String toString() const;

	int size() const;
};
