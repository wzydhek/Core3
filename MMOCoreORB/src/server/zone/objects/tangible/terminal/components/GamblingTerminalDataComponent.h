/*
 * GamblingTerminalDataComponent.h
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class GamblingTerminalDataComponent : public DataObjectComponent {
protected:

	uint64 bank;
	SerializableString game;

public:
	GamblingTerminalDataComponent();

	virtual ~GamblingTerminalDataComponent();

	void writeJSON(nlohmann::json& j) const;

	/**
	 * Set the game for this terminal
	 */
	void setGame(String g);

	/**
	 * Get the game for this terminal
	 */
	String getGame();

	/**
	 * Get the bank for this terminal
	 */
	uint64 getBank();

	/**
	 * Remove money form this games bank
	 */
	void deductFromBank(uint64 amount);

	/**
	 * Add money to this games bank
	 */
	void addToBank(uint64 amount);

	/**
	 * Is this a gambling terminal data component
	 */
	bool isGamblingTerminalData();
};
