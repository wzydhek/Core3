#include "AiSpeciesData.h"

AiSpeciesData::AiSpeciesData(int species, String skel, bool sit, bool liedown) : Object() {
	speciesID = species;
	skeleton = skel;
	canSit = sit;
	canLie = liedown;
}

AiSpeciesData::~AiSpeciesData() {
}

int AiSpeciesData::getSpeciesID() const {
	return speciesID;
}

const String& AiSpeciesData::getSkeleton() const {
	return skeleton;
}

bool AiSpeciesData::canSitDown() const {
	return canSit;
}

bool AiSpeciesData::canLieDown() const {
	return canLie;
}