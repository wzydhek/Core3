/*
 * FactionRank.h
 *
 *  Created on: 15/01/2012
 *      Author: victor
 */

#pragma once

#include "FactionRank.h"

class DataTableIff;

class FactionRanks {
protected:
	Vector<FactionRank> ranks;

public:
	FactionRanks();
	FactionRanks(const FactionRanks& f);

	void readObject(DataTableIff* table);

	const FactionRank& getRank(int index);

	int getCount();
};
