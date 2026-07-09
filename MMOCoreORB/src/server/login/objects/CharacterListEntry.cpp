#include "CharacterListEntry.h"

CharacterListEntry::CharacterListEntry(const CharacterListEntry& e) : Object() {
	objectID = e.objectID;
	accountID = e.accountID;
	galaxyID = e.galaxyID;
	firstName = e.firstName;
	surName = e.surName;
	race = e.race;
	gender = e.gender;
	creationDate = e.creationDate;

	galaxyName = e.galaxyName;
	banReason = e.banReason;
	banAdmin = e.banAdmin;
	banExpiration = e.banExpiration;
}

CharacterListEntry& CharacterListEntry::operator=(const CharacterListEntry& e) {
	if (this == &e)
		return *this;

	objectID = e.objectID;
	accountID = e.accountID;
	galaxyID = e.galaxyID;
	firstName = e.firstName;
	surName = e.surName;
	race = e.race;
	gender = e.gender;
	creationDate = e.creationDate;

	galaxyName = e.galaxyName;
	banReason = e.banReason;
	banAdmin = e.banAdmin;
	banExpiration = e.banExpiration;

	return *this;
}

CharacterListEntry::~CharacterListEntry() {
}

uint32 CharacterListEntry::getAccountID() const {
	return accountID;
}

const Time& CharacterListEntry::getCreationDate() const {
	return creationDate;
}

const String& CharacterListEntry::getFirstName() const {
	return firstName;
}

uint32 CharacterListEntry::getGalaxyID() const {
	return galaxyID;
}

const String& CharacterListEntry::getGalaxyName() const {
	return galaxyName;
}

uint32 CharacterListEntry::getGender() const {
	return gender;
}

uint64 CharacterListEntry::getObjectID() const {
	return objectID;
}

uint32 CharacterListEntry::getRace() const {
	return race;
}

const String& CharacterListEntry::getSurName() const {
	return surName;
}

void CharacterListEntry::setAccountID(uint32 accountID) {
	this->accountID = accountID;
}

void CharacterListEntry::setCreationDate(Time creationDate) {
	this->creationDate = creationDate;
}

void CharacterListEntry::setFirstName(String firstName) {
	this->firstName = firstName;
}

void CharacterListEntry::setGalaxyName(String galaxyName) {
	this->galaxyName = galaxyName;
}

void CharacterListEntry::setGalaxyID(uint32 galaxyID) {
	this->galaxyID = galaxyID;
}

void CharacterListEntry::setGender(uint32 gender) {
	this->gender = gender;
}

void CharacterListEntry::setObjectID(uint64 objectID) {
	this->objectID = objectID;
}

void CharacterListEntry::setRace(uint32 race) {
	this->race = race;
}

void CharacterListEntry::setSurName(String surName) {
	this->surName = surName;
}

String CharacterListEntry::getFullName() const {
	StringBuffer fullName;
	fullName << firstName;

	if (!surName.isEmpty())
		fullName << " " << surName;

	return fullName.toString();
}

bool CharacterListEntry::isBanned() const {
	return !banExpiration.isPast();
}

void CharacterListEntry::setBanReason(const String& banReason) {
	this->banReason = banReason;
}

const String& CharacterListEntry::getBanReason() const {
	return banReason;
}

void CharacterListEntry::setBanExpiration(Time banExpiration) {
	this->banExpiration = banExpiration;
}

uint32 CharacterListEntry::getBanExpiration() const {
	return banExpiration.getTime();
}

void CharacterListEntry::setBanAdmin(uint32 banAdmin) {
	this->banAdmin = banAdmin;
}

uint32 CharacterListEntry::getBanAdmin() const {
	return banAdmin;
}

String CharacterListEntry::toString() const {
	StringBuffer buf;
	buf << "CharacterListEntry("
		<< "name: " << getFullName() << ", oid: " << objectID << ", galaxy: " << galaxyID << ", account: " << accountID << ")";
	return buf.toString();
}

String CharacterListEntry::toStringData() const {
	return toString();
}