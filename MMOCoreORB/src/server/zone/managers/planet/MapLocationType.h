/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang/String.h"

class MapLocationType {
public:

	static const int UNKNOWN = 1;
	static const int BANK = 2;
	static const int CANTINA = 3;
	static const int CAPITOL = 4;
	static const int CLONING_FACILITY = 5;
	static const int PARKING_GARAGE = 6;

	static const int GUILD_HALL = 7;
	static const int GUILD_COMBAT = 8;
	static const int GUILD_COMMERCE = 9;
	static const int GUILD_THEATER = 10;
	static const int GUILD_UNIVERSITY = 11;

	static const int HOTEL = 12;
	static const int MEDICAL_CENTER = 13;
	static const int SHUTTLEPORT = 14;
	static const int STARPORT = 15;
	static const int THEME_PARK = 16;
	static const int CITY = 17;
	static const int INVISIBLE = 18;

	static const int TRAINER = 19;
	static const int TRAINER_BRAWLER = 20;
	static const int TRAINER_ARTISAN = 21;
	static const int TRAINER_SCOUT = 22;
	static const int TRAINER_MARKSMAN = 23;
	static const int TRAINER_ENTERTAINER = 24;
	static const int TRAINER_MEDIC = 25;
	static const int TRAINER_STARFIGHTER_ENGINEER_TRAINER = 62;
	static const int TRAINER_SHIPWRIGHT = 63;
	static const int TRAINER_PRIVATEER_PILOT = 64;
	static const int TRAINER_REBEL_PILOT = 65;
	static const int TRAINER_IMPERIAL_PILOT = 66;

	static const int JUNK_SHOP = 26;
	static const int TAVERN = 27;
	static const int BARRACKS = 28;

	static const int VENDOR = 29;
	static const int VENDOR_ARMOR = 30;
	static const int VENDOR_CLOTHING = 31;
	static const int VENDOR_COMPONENTS = 32;
	static const int VENDOR_DROIDS = 33;
	static const int VENDOR_EQUIPMENT = 34;
	static const int VENDOR_FOOD = 35;
	static const int VENDOR_HOUSING = 36;
	static const int VENDOR_RESOURCES = 37;
	static const int VENDOR_TOOLS = 38;
	static const int VENDOR_WEAPONS = 39;
	static const int VENDOR_JUNK = 40;
	static const int VENDOR_PETS = 52;
	static const int VENDOR_MEDICAL_SUPPLIES = 53;

	static const int TERMINAL = 41;
	static const int TERMINAL_BANK = 42;
	static const int TERMINAL_BAZAAR = 43;
	static const int TERMINAL_MISSION = 44;

	static const int REBEL = 45;
	static const int REBEL_HEADQUARTERS = 47;

	static const int IMPERIAL = 46;
	static const int IMPERIAL_HEADQUARTERS = 48;

	static const int CAMP = 49;
	static const int CITY_HALL = 50;
	static const int PLAYER_THEATER = 51;
	static const int PLAYER_INVISIBLE = 54;
	static const int PLAYER_PARKING_GARAGE = 55;
	static const int MUSEUM = 56;
	static const int SALON = 57;

	static const int SPACE = 58;
	static const int SPACE_RECRUITER = 59;
	static const int SPACE_STARSHIP_CHASSIS_BROKER = 60;
	static const int SPACE_STARSHIP_CHASSIS = 61; // ??
	static const int SPACE_SHIPS = 67; // ??


	static String getMapLocationName(uint8 maptype);

};
