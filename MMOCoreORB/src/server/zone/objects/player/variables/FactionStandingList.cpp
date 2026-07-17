#include "FactionStandingList.h"

FactionStandingList::FactionStandingList() {
	factions.setAllowOverwriteInsertPlan();
	factions.setNullValue(0.f);

	rebelPoints = 0;
	imperialPoints = 0;

	addSerializableVariables();
}

FactionStandingList::FactionStandingList(const FactionStandingList& f) : Object(), Serializable() {
	factions.setAllowOverwriteInsertPlan();
	factions.setNullValue(0.f);

	factionRank = f.factionRank;
	rebelPoints = f.rebelPoints;
	imperialPoints = f.imperialPoints;
	factions = f.factions;

	addSerializableVariables();
}

FactionStandingList& FactionStandingList::operator=(const FactionStandingList& f) {
	if (this == &f)
		return *this;

	factionRank = f.factionRank;
	rebelPoints = f.rebelPoints;
	imperialPoints = f.imperialPoints;
	factions = f.factions;

	return *this;
}

void FactionStandingList::addSerializableVariables() {
	addSerializableVariable("factionRank", &factionRank);
	addSerializableVariable("rebelPoints", &rebelPoints);
	addSerializableVariable("imperialPoints", &imperialPoints);
	addSerializableVariable("factions", &factions);
}

void server::zone::objects::player::variables::to_json(nlohmann::json& j, const FactionStandingList& l) {
	j["factionRank"] = l.factionRank;
	j["rebelPoints"] = l.rebelPoints;
	j["imperialPoints"] = l.imperialPoints;
	j["factions"] = l.factions.getMapUnsafe();
}

float FactionStandingList::get(const String& faction) const {
	return getFactionStanding(faction);
}

int FactionStandingList::size() const {
	return factions.size();
}

void FactionStandingList::put(const String& faction, float amount) {
	if (faction == "imperial")
		setImperialPoints(amount);
	else if (faction == "rebel")
		setRebelPoints(amount);
	else
		factions.put(faction, amount);
}

float FactionStandingList::getFactionStanding(const String& faction) const {
	if (faction == "imperial")
		return getImperialPoints();
	else if (faction == "rebel")
		return getRebelPoints();
	else
		return factions.get(faction);
}

bool FactionStandingList::contains(const String& faction) const {
	if (faction == "imperial" || faction == "rebel")
		return true;
	else
		return factions.contains(faction);
}

bool FactionStandingList::isPvpFaction(const String& faction) const {
	return faction == "imperial" || faction == "rebel";
}

const String& FactionStandingList::getFactionRank() const {
	return factionRank;
}

void FactionStandingList::setRebelPoints(int amount) {
	rebelPoints = amount;
}

void FactionStandingList::setImperialPoints(int amount) {
	imperialPoints = amount;
}

void FactionStandingList::increaseRebelPoints(int amount) {
	rebelPoints += amount;
}

void FactionStandingList::decreaseRebelPoints(int amount) {
	rebelPoints -= amount;
}

void FactionStandingList::increaseImperialPoints(int amount) {
	imperialPoints += amount;
}

void FactionStandingList::decreaseImperialPoints(int amount) {
	imperialPoints -= amount;
}

void FactionStandingList::setFactionRank(const String& rank) {
	factionRank = rank;
}

int FactionStandingList::getImperialPoints() const {
	return imperialPoints;
}

int FactionStandingList::getRebelPoints() const {
	return rebelPoints;
}

int FactionStandingList::getHuttPoints() const {
	return 0;
}

void FactionStandingList::insertToMessage(BaseMessage* message) const {
	message->insertAscii(factionRank);
	message->insertInt(rebelPoints);
	message->insertInt(imperialPoints);
	message->insertInt(0); // Hutt Points;

	int listSize = factions.size();

	message->insertInt(listSize);

	for (int i = 0; i < listSize; ++i) {
		auto key = factions.getKey(i);

		message->insertAscii(key);
	}

	message->insertInt(listSize);

	for (int i = 0; i < listSize; ++i)
		message->insertFloat(factions.get(i));
}