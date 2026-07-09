#include "ComponentSlots.h"

String Components::shipComponentSlotToString(int slot) {
	switch (slot) {
		case Components::CHASSIS:
			return "chassis";
		case Components::REACTOR:
			return "reactor";
		case Components::ENGINE:
			return "engine";
		case Components::SHIELD0:
			return "shield_0";
		case Components::SHIELD1:
			return "shield_1";
		case Components::ARMOR0:
			return "armor_0";
		case Components::ARMOR1:
			return "armor_1";
		case Components::CAPACITOR:
			return "capacitor";
		case Components::BOOSTER:
			return "booster";
		case Components::DROID_INTERFACE:
			return "droid_interface";
		case Components::BRIDGE:
			return "bridge";
		case Components::HANGAR:
			return "hangar";
		case Components::TARGETING_STATION:
			return "targeting_station";
		default: {
			if (slot >= WEAPON_START && slot <= CAPITALSLOTMAX) {
				return "weapon_" + String::valueOf(slot - Components::WEAPON_START);
			} else {
				return "";
			}
		}
	}
}