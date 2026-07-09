/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableRow.h"
#include "templates/manager/TemplateManager.h"
#include "CreatureLocomotion.h"

class CreatureMovementEntry : public Variable {
public:
	UnsignedCharacter posture;
	UnsignedCharacter stationary;
	UnsignedCharacter slow;
	UnsignedCharacter fast;
	Float movementScale;
	Float accelerationScale;
	Float turnScale;
	Float canSeeHeightMod;

	CreatureMovementEntry();

	CreatureMovementEntry(const CreatureMovementEntry& m);

	CreatureMovementEntry& operator=(const CreatureMovementEntry& m);

	bool operator==(CreatureMovementEntry entry);

	bool toString(String& str) const;

	bool parseFromString(const String& str, int version = 0);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};

class CreaturePosture : public Singleton<CreaturePosture>, public Object, public Logger {
public:

	enum {
		INVALID        = 0xFF,
		UPRIGHT        = 0,
		CROUCHED       = 1,
		PRONE          = 2,
		SNEAKING       = 3,
		BLOCKING       = 4,
		CLIMBING       = 5,
		FLYING         = 6,
		LYINGDOWN      = 7,
		SITTING        = 8,
		SKILLANIMATING = 9,
		DRIVINGVEHICLE = 10,
		RIDINGCREATURE = 11,
		KNOCKEDDOWN    = 12,
		INCAPACITATED  = 13,
		DEAD           = 14
	};

	HashTable<uint8, CreatureMovementEntry> movementTable;
	HashTable<uint8, int> rangedAttackMod;
	HashTable<uint8, int> rangedDefenseMod;
	HashTable<uint8, int> meleeAttackMod;
	HashTable<uint8, int> meleeDefenseMod;

	CreaturePosture();

	~CreaturePosture();

	static const String postureToString(uint8 posture);

	uint8 getLocomotion(uint8 pos, uint8 speed) const;

	uint8 getSpeed(uint8 pos, uint8 loc) const;

	float getMovementScale(uint8 pos) const;

	float getAccelerationScale(uint8 pos) const;

	float getTurnScale(uint8 pos) const;

	float getCanSeeHeightMod(uint8 pos) const;

	void loadMovementData();

	int getRangedAttackMod(uint8 loc) const;

	int getRangedDefenseMod(uint8 loc) const;

	int getMeleeAttackMod(uint8 loc) const;

	int getMeleeDefenseMod(uint8 loc) const;
};
