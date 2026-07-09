#include "GalaxyBanEntry.h"

GalaxyBanEntry::GalaxyBanEntry(const GalaxyBanEntry& e) : Object() {
	accountID = e.accountID;
	creationDate = e.creationDate;
	galaxyID = e.galaxyID;
	banReason = e.banReason;
	banAdmin = e.banAdmin;
	banExpiration = e.banExpiration;
}

GalaxyBanEntry& GalaxyBanEntry::operator=(const GalaxyBanEntry& e) {
	if (this == &e)
		return *this;

	accountID = e.accountID;
	creationDate = e.creationDate;
	galaxyID = e.galaxyID;
	banReason = e.banReason;
	banAdmin = e.banAdmin;
	banExpiration = e.banExpiration;

	return *this;
}

GalaxyBanEntry::~GalaxyBanEntry() {
}

uint32 GalaxyBanEntry::getAccountID() const {
	return accountID;
}

const Time& GalaxyBanEntry::getCreationDate() const {
	return creationDate;
}

uint32 GalaxyBanEntry::getGalaxyID() const {
	return galaxyID;
}

void GalaxyBanEntry::setAccountID(uint32 accountID) {
	this->accountID = accountID;
}

void GalaxyBanEntry::setCreationDate(Time creationDate) {
	this->creationDate = creationDate;
}

void GalaxyBanEntry::setGalaxyID(uint32 galaxyID) {
	this->galaxyID = galaxyID;
}

void GalaxyBanEntry::setBanReason(String banReason) {
	this->banReason = banReason;
}

const String& GalaxyBanEntry::getBanReason() const {
	return banReason;
}

void GalaxyBanEntry::setBanExpiration(Time banExpiration) {
	this->banExpiration = banExpiration;
}

uint32 GalaxyBanEntry::getBanExpiration() const {
	return banExpiration.getTime();
}

void GalaxyBanEntry::setBanAdmin(uint32 banAdmin) {
	this->banAdmin = banAdmin;
}

uint32 GalaxyBanEntry::getBanAdmin() const {
	return banAdmin;
}