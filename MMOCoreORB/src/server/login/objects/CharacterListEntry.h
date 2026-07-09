/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang/Object.h"

class CharacterListEntry : public Object {
private:
	uint64 objectID = 0;
	uint32 accountID = 0;
	uint32 galaxyID = 0;
	String firstName;
	String surName;
	uint32 race = 0;
	uint32 gender = 0;
	Time creationDate;

	String galaxyName;
	String banReason;
	uint32 banAdmin = 0;
	Time banExpiration;

public:
	CharacterListEntry() = default;


	CharacterListEntry(const CharacterListEntry& e);

	CharacterListEntry& operator=(const CharacterListEntry& e);

	~CharacterListEntry();

	uint32 getAccountID() const;

	const Time& getCreationDate() const;

	const String& getFirstName() const;

	uint32 getGalaxyID() const;

	const String& getGalaxyName() const;

	uint32 getGender() const;

	uint64 getObjectID() const;

	uint32 getRace() const;

	const String& getSurName() const;

	void setAccountID(uint32 accountID);

	void setCreationDate(Time creationDate);

	void setFirstName(String firstName);

	void setGalaxyName(String galaxyName);

	void setGalaxyID(uint32 galaxyID);

	void setGender(uint32 gender);

	void setObjectID(uint64 objectID);

	void setRace(uint32 race);

	void setSurName(String surName);

	String getFullName() const;


	bool isBanned() const;

	void setBanReason(const String& banReason);

	const String& getBanReason() const;

	void setBanExpiration(Time banExpiration);

	uint32 getBanExpiration() const;

	void setBanAdmin(uint32 banAdmin);

	uint32 getBanAdmin() const;

	String toString() const;

	String toStringData() const;
};
