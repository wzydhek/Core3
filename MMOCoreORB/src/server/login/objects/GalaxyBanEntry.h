/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "system/lang/Object.h"

class GalaxyBanEntry : public Object {
private:
	uint32 accountID = 0;
	Time creationDate;
	int galaxyID = 0;
	String banReason;
	uint32 banAdmin = 0;
	Time banExpiration;

public:
	GalaxyBanEntry() = default;

	GalaxyBanEntry(const GalaxyBanEntry& e);

	GalaxyBanEntry& operator=(const GalaxyBanEntry& e);

	~GalaxyBanEntry();

	uint32 getAccountID() const;

	const Time& getCreationDate() const;

	uint32 getGalaxyID() const;

	void setAccountID(uint32 accountID);

	void setCreationDate(Time creationDate);

	void setGalaxyID(uint32 galaxyID);

	void setBanReason(String banReason);

	const String& getBanReason() const;

	void setBanExpiration(Time banExpiration);

	uint32 getBanExpiration() const;

	void setBanAdmin(uint32 banAdmin);

	uint32 getBanAdmin() const;
};
