#include "FactionRank.h"

FactionRank::FactionRank() {
	cost = 0;
	delegateRatioFrom = 0;
	delegateRatioTo = 0;
}

FactionRank::FactionRank(const FactionRank& f) : Object() {
	name = f.name;
	cost = f.cost;
	delegateRatioFrom = f.delegateRatioFrom;
	delegateRatioTo = f.delegateRatioTo;
}

FactionRank& FactionRank::operator=(const FactionRank& f) {
	if (this == &f)
		return *this;

	name = f.name;
	cost = f.cost;
	delegateRatioFrom = f.delegateRatioFrom;
	delegateRatioTo = f.delegateRatioTo;

	return *this;
}

void FactionRank::readObject(DataTableRow* row) {
	row->getValue(1, name);
	row->getValue(2, cost);
	row->getValue(3, delegateRatioFrom);
	row->getValue(4, delegateRatioTo);
}

int FactionRank::getCost() const {
	return cost;
}

int FactionRank::getDelegateRatioFrom() const {
	return delegateRatioFrom;
}

int FactionRank::getDelegateRatioTo() const {
	return delegateRatioTo;
}

const String& FactionRank::getName() const {
	return name;
}

void FactionRank::setCost(int cost) {
	this->cost = cost;
}

void FactionRank::setDelegateRatioFrom(int delegateRatioFrom) {
	this->delegateRatioFrom = delegateRatioFrom;
}

void FactionRank::setDelegateRatioTo(int delegateRatioTo) {
	this->delegateRatioTo = delegateRatioTo;
}

void FactionRank::setName(const String& name) {
	this->name = name;
}