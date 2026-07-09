#include "Races.h"

const char* Races::getRace(int raceid) {
	if (raceid < 0 || raceid > 19)
		return "";

	return RaceStrs[raceid];
}

 int Races::getSpeciesID(int raceid) {
	if (raceid < 0 || raceid > 19)
		return 0;

	return TemplateSpecies[raceid];
}

const char* Races::getSpecies(int raceid) {
	if (raceid < 0 || raceid > 19)
		return "";

	return Species[raceid];
}

const char* Races::getGender(int raceid) {
	if (raceid < 0 || raceid > 19)
		return "";

	return Gender[raceid];
}

uint32 Races::getRaceCRC(int raceid) {
	if (raceid < 0 || raceid > 19)
		return 0;

	return SharedRace[raceid];
}

const char* Races::getCompleteRace(uint32 sharedRaceCRC) {
	int race = -1;
	for (int i = 0; i < 20; ++i) {
		if (SharedRace[i] == sharedRaceCRC) {
			race = i;
			break;
		}
	}

	if (race == -1)
		return "";
	else
		return CCRaceStrs[race];
}

int Races::getRaceID(const String& name) {
	for (int i = 0; i < 20; i++) {
		if (strcmp(name.toCharArray(), CCRaceStrs[i]) == 0)
			return i;
	}

	return 0;
}

unsigned int* Races::getAttribLimits(int raceid) {
	return attributeLimits[raceid % 10];
}