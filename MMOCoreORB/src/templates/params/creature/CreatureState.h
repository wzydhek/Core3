/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableRow.h"
#include "templates/manager/TemplateManager.h"

class CreatureState : public Singleton<CreatureState>, public Logger, public Object {
public:
	HashTable<String, uint64> states;

	//enum class State : __int64 {
	enum {
		INVALID                  = 0x00,
		COVER                    = 0x01,
		COMBAT                   = 0x02,
		PEACE                    = 0x04,
		AIMING                   = 0x08,
		ALERT                    = 0x10,
		BERSERK                  = 0x20,
		FEIGNDEATH               = 0x40,
		COMBATATTITUDEEVASIVE    = 0x80,
		COMBATATTITUDENORMAL     = 0x100,
		COMBATATTITUDEAGGRESSIVE = 0x200,
		TUMBLING                 = 0x400,
		RALLIED                  = 0x800,
		STUNNED                  = 0x1000,
		BLINDED                  = 0x2000,
		DIZZY                    = 0x4000,
		INTIMIDATED              = 0x8000,
		IMMOBILIZED              = 0x10000,
		FROZEN                   = 0x20000,
		SWIMMING                 = 0x40000,
		SITTINGONCHAIR           = 0x80000,
		CRAFTING                 = 0x100000,
		GLOWINGJEDI              = 0x200000,
		MASKSCENT                = 0x400000,
		POISONED                 = 0x800000,
		BLEEDING                 = 0x1000000,
		DISEASED                 = 0x2000000,
		ONFIRE                   = 0x4000000,
		RIDINGMOUNT              = 0x8000000, // Is riding a vehicle or creature mount
		MOUNTEDCREATURE          = 0x10000000, // Is a vehicle or creature mount that has a rider
		PILOTINGSHIP             = 0x20000000,
		SHIPOPERATIONS           = 0x40000000,
		SHIPGUNNER               = 0x80000000,
		SHIPINTERIOR             = 0x100000000,
		PILOTINGPOBSHIP          = 0x200000000,
	};

	void loadStateData();

	uint64 getState(const String& state) const;

	String getSpecialName(const uint64 state, bool initialCap = false) const;

	String getName(const uint64 state, bool initialCap = false) const;
};
