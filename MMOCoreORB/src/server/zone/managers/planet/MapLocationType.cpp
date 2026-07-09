#include "MapLocationType.h"

String MapLocationType::getMapLocationName(uint8 maptype) {
	String name = "";

	switch (maptype) {
		case UNKNOWN:
			name = "@map_loc_cat_n:unknown";
			break;
		case BANK:
			name = "@map_loc_cat_n:bank";
			break;
		case CANTINA:
			name = "@map_loc_cat_n:cantina";
			break;
		case CAPITOL:
			name = "@map_loc_cat_n:capitol";
			break;
		case CLONING_FACILITY:
			name = "@map_loc_cat_n:cloningfacility";
			break;
		case PARKING_GARAGE:
			name = "@map_loc_cat_n:garage";
			break;
		case GUILD_HALL:
			name = "@map_loc_cat_n:guild";
			break;
		case GUILD_COMBAT:
			name = "@map_loc_cat_n:guild_combat";
			break;
		case GUILD_COMMERCE:
			name = "@map_loc_cat_n:guild_commerce";
			break;
		case GUILD_THEATER:
			name = "@map_loc_cat_n:guild_theater";
			break;
		case GUILD_UNIVERSITY:
			name = "@map_loc_cat_n:guild_university";
			break;
		case HOTEL:
			name = "@map_loc_cat_n:hotel";
			break;
		case MEDICAL_CENTER:
			name = "@map_loc_cat_n:medicalcenter";
			break;
		case SHUTTLEPORT:
			name = "@map_loc_cat_n:shuttleport";
			break;
		case STARPORT:
			name = "@map_loc_cat_n:starport";
			break;
		case THEME_PARK:
			name = "@map_loc_cat_n:themepark";
			break;
		case CITY:
			name = "@map_loc_cat_n:city";
			break;
		case INVISIBLE:
			name = "@map_loc_cat_n:other";
			break;
		case TRAINER:
			name = "@map_loc_cat_n:trainer";
			break;
		case TRAINER_BRAWLER:
			name = "@map_loc_cat_n:trainer_brawler";
			break;
		case TRAINER_ARTISAN:
			name = "@map_loc_cat_n:trainer_artisan";
			break;
		case TRAINER_SCOUT:
			name = "@map_loc_cat_n:trainer_scout";
			break;
		case TRAINER_MARKSMAN:
			name = "@map_loc_cat_n:trainer_marksman";
			break;
		case TRAINER_ENTERTAINER:
			name = "@map_loc_cat_n:trainer_entertainer";
			break;
		case TRAINER_MEDIC:
			name = "@map_loc_cat_n:trainer_medic";
			break;
		case TRAINER_STARFIGHTER_ENGINEER_TRAINER:
			name = "@map_loc_cat_n:trainer_starfighter_engineer";
			break;
		case TRAINER_SHIPWRIGHT:
			name = "@map_loc_cat_n:trainer_shipwright";
			break;
		case TRAINER_PRIVATEER_PILOT:
			name = "@find_display:trainer_pilot_privateer";
			break;
		case TRAINER_REBEL_PILOT:
			name = "@map_loc_cat_n:trainer_pilot_rebel";
			break;
		case TRAINER_IMPERIAL_PILOT:
			name = "@map_loc_cat_n:trainer_pilot_imperial";
			break;
		case JUNK_SHOP:
			name = "@map_loc_cat_n:junkshop";
			break;
		case TAVERN:
			name = "@map_loc_cat_n:tavern";
			break;
		case BARRACKS:
			name = "@map_loc_cat_n:barracks";
			break;
		case VENDOR:
			name = "@map_loc_cat_n:vendor";
			break;
		case VENDOR_JUNK:
			name = "@map_loc_cat_n:vendor_junk";
			break;
		case VENDOR_ARMOR:
			name = "@map_loc_cat_n:vendor_armor";
			break;
		case VENDOR_CLOTHING:
			name = "@map_loc_cat_n:vendor_clothing";
			break;
		case VENDOR_COMPONENTS:
			name = "@map_loc_cat_n:vendor_components";
			break;
		case VENDOR_DROIDS:
			name = "@map_loc_cat_n:vendor_droids";
			break;
		case VENDOR_EQUIPMENT:
			name = "@map_loc_cat_n:vendor_equipment";
			break;
		case VENDOR_FOOD:
			name = "@map_loc_cat_n:vendor_food";
			break;
		case VENDOR_HOUSING:
			name = "@map_loc_cat_n:vendor_housing";
			break;
		case VENDOR_RESOURCES:
			name = "@map_loc_cat_n:vendor_resources";
			break;
		case VENDOR_TOOLS:
			name = "@map_loc_cat_n:vendor_tools";
			break;
		case VENDOR_WEAPONS:
			name = "@map_loc_cat_n:vendor_weapons";
			break;
		case VENDOR_PETS:
			name = "@map_loc_cat_n:vendor_pets";
			break;
		case VENDOR_MEDICAL_SUPPLIES:
			name = "@map_loc_cat_n:vendor_medical";
			break;
		case TERMINAL:
			name = "@map_loc_cat_n:terminal";
			break;
		case TERMINAL_BANK:
			name = "@map_loc_cat_n:terminal_bank";
			break;
		case TERMINAL_BAZAAR:
			name = "@map_loc_cat_n:terminal_bazaar";
			break;
		case TERMINAL_MISSION:
			name = "@map_loc_cat_n:terminal_mission";
			break;
		case REBEL:
			name = "@map_loc_cat_n:rebel";
			break;
		case REBEL_HEADQUARTERS:
			name = "@map_loc_cat_n:rebel_hq";
			break;
		case IMPERIAL:
			name = "@map_loc_cat_n:imperial";
			break;
		case IMPERIAL_HEADQUARTERS:
			name = "@map_loc_cat_n:imperial_hq";
			break;
		case CAMP:
			name = "@map_loc_cat_n:camp";
			break;
		case CITY_HALL:
			name = "@map_loc_cat_n:cityhall";
			break;
		case PLAYER_THEATER:
			name = "@map_loc_cat_n:theater";
			break;
		case PLAYER_PARKING_GARAGE:
			name = "@map_loc_cat_n:garage";
			break;
		case PLAYER_INVISIBLE:
			name = "@map_loc_cat_n:other";
			break;
		case MUSEUM:
			name = "@map_loc_cat_n:museum";
			break;
		case SALON:
			name = "@map_loc_cat_n:salon";
			break;
		default:
			name = "@map_loc_cat_n:other";
			break;
	}

	return name;
}