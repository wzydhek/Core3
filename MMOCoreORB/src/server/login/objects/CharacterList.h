/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/db/ServerDatabase.h"
#include "../objects/GalaxyList.h"
#include "CharacterListEntry.h"

#ifdef WITH_SWGREALMS_API
	#include "server/login/SWGRealmsAPI.h"
#endif

class CharacterList : public Vector<CharacterListEntry> {
	uint32 accountid;
	String username;

public:
	CharacterList(uint32 id, String user);

	~CharacterList();

	void update();
};
