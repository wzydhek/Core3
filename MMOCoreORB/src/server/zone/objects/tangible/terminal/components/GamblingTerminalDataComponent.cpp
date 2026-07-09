#include "GamblingTerminalDataComponent.h"

GamblingTerminalDataComponent::GamblingTerminalDataComponent() {
	bank = 0;
	game = "default";
	addSerializableVariable("bank", &bank);
	addSerializableVariable("game", &game);
}

GamblingTerminalDataComponent::~GamblingTerminalDataComponent() {
}

void GamblingTerminalDataComponent::writeJSON(nlohmann::json& j) const {
	DataObjectComponent::writeJSON(j);

	SERIALIZE_JSON_MEMBER(bank)
	SERIALIZE_JSON_MEMBER(game);
}

/**
 * Set the game for this terminal
 */
void GamblingTerminalDataComponent::setGame(String g) {
	game = g;
}

/**
 * Get the game for this terminal
 */
String GamblingTerminalDataComponent::getGame() {
	return game;
}

/**
 * Get the bank for this terminal
 */
uint64 GamblingTerminalDataComponent::getBank() {
	return bank;
}

/**
 * Remove money form this games bank
 */
void GamblingTerminalDataComponent::deductFromBank(uint64 amount) {
	if (amount < bank)
		bank -= amount;
}

/**
 * Add money to this games bank
 */
void GamblingTerminalDataComponent::addToBank(uint64 amount) {
	bank += amount;
}

/**
 * Is this a gambling terminal data component
 */
bool GamblingTerminalDataComponent::isGamblingTerminalData() {
	return true;
}