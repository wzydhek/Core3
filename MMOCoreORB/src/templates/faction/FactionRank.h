/*
 * FactionRank.h
 *
 *  Created on: 15/01/2012
 *      Author: victor
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

class FactionRank : public Object {
protected:
	String name;
	int cost;
	int delegateRatioFrom;
	int delegateRatioTo;

public:
	FactionRank();

	FactionRank(const FactionRank& f);

	FactionRank& operator=(const FactionRank& f);

	void readObject(DataTableRow* row);

	int getCost() const;

	int getDelegateRatioFrom() const;

	int getDelegateRatioTo() const;

	const String& getName() const;

	void setCost(int cost);

	void setDelegateRatioFrom(int delegateRatioFrom);

	void setDelegateRatioTo(int delegateRatioTo);

	void setName(const String& name);

};
