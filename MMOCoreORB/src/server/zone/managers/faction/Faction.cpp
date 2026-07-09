#include "Faction.h"

Faction::Faction() : Object() {
	playerAllowed = true;
	adjustFactor = 1.0;
}

Faction::Faction(const String& name) : Object() {
	factionName = name;
	playerAllowed = true;
	adjustFactor = 1.0;
}

Faction::Faction(const Faction& f) : Object() {
	factionName = f.factionName;
	playerAllowed = f.playerAllowed;
	enemies = f.enemies;
	allies = f.allies;
	adjustFactor = f.adjustFactor;
}

Faction& Faction::operator=(const Faction& f) {
	if (this == &f)
		return *this;

	factionName = f.factionName;
	playerAllowed = f.playerAllowed;
	enemies = f.enemies;
	allies = f.allies;
	adjustFactor = f.adjustFactor;

	return *this;
}

void Faction::parseEnemiesFromList(const String& list) {
	StringTokenizer tokenizer(list);
	tokenizer.setDelimeter(",");

	while (tokenizer.hasMoreTokens()) {
		String token;
		tokenizer.getStringToken(token);

		enemies.put(token);
	}
}

void Faction::parseAlliesFromList(const String& list) {
	StringTokenizer tokenizer(list);
	tokenizer.setDelimeter(",");

	while (tokenizer.hasMoreTokens()) {
		String token;
		tokenizer.getStringToken(token);

		allies.put(token);
	}
}

const String& Faction::getFactionName() const {
	return factionName;
}

void Faction::setPlayerAllowed(bool allowed) {
	playerAllowed = allowed;
}

void Faction::setAdjustFactor(float factor) {
	adjustFactor = factor;
}

const SortedVector<String>* Faction::getEnemies() const {
	return &enemies;
}

const SortedVector<String>* Faction::getAllies() const {
	return &allies;
}

bool Faction::isPlayerAllowed() const {
	return playerAllowed;
}

float Faction::getAdjustFactor() const {
	return adjustFactor;
}