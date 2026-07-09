#include "ArmorObjectTemplate.h"

ArmorObjectTemplate::ArmorObjectTemplate() {
	healthEncumbrance = 0;
	actionEncumbrance = 0;
	mindEncumbrance = 0;

	rating = 0;

	kinetic = 0;
	energy = 0;
	electricity = 0;
	stun = 0;
	blast = 0;
	heat = 0;
	cold = 0;
	acid = 0;
	lightSaber = 0;

	vulnerabilites = 0;
	specialResists = 0;

	hitLocation = NOLOCATION;
}

ArmorObjectTemplate::~ArmorObjectTemplate() {
}

void ArmorObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	vulnerabilites = templateData->getIntField("vulnerability");
	specialResists = templateData->getIntField("specialResists");

	healthEncumbrance = templateData->getIntField("healthEncumbrance");
	actionEncumbrance = templateData->getIntField("actionEncumbrance");
	mindEncumbrance = templateData->getIntField("mindEncumbrance");

	rating = templateData->getIntField("rating");

	kinetic = templateData->getFloatField("kinetic");
	energy = templateData->getFloatField("energy");
	electricity = templateData->getFloatField("electricity");
	stun = templateData->getFloatField("stun");
	blast = templateData->getFloatField("blast");
	heat = templateData->getFloatField("heat");
	cold = templateData->getFloatField("cold");
	acid = templateData->getFloatField("acid");
	lightSaber = templateData->getFloatField("lightSaber");

	hitLocation = templateData->getIntField("hitLocation");
}

float ArmorObjectTemplate::getAcid() const {
	return acid;
}

int ArmorObjectTemplate::getActionEncumbrance() const {
	return actionEncumbrance;
}

float ArmorObjectTemplate::getBlast() const {
	return blast;
}

float ArmorObjectTemplate::getCold() const {
	return cold;
}

float ArmorObjectTemplate::getElectricity() const {
	return electricity;
}

float ArmorObjectTemplate::getEnergy() const {
	return energy;
}

int ArmorObjectTemplate::getHealthEncumbrance() const {
	return healthEncumbrance;
}

float ArmorObjectTemplate::getHeat() const {
	return heat;
}

float ArmorObjectTemplate::getKinetic() const {
	return kinetic;
}

float ArmorObjectTemplate::getLightSaber() const {
	return lightSaber;
}

int ArmorObjectTemplate::getMindEncumbrance() const {
	return mindEncumbrance;
}

int ArmorObjectTemplate::getRating() const {
	return rating;
}

float ArmorObjectTemplate::getStun() const {
	return stun;
}

int ArmorObjectTemplate::getVulnerabilites() const {
	return vulnerabilites;
}

int ArmorObjectTemplate::getSpecialResists() const {
	return specialResists;
}

int ArmorObjectTemplate::getHitLocation() const {
	return hitLocation;
}

void ArmorObjectTemplate::setAcid(float acid) {
	this->acid = acid;
}

void ArmorObjectTemplate::setActionEncumbrance(int actionEncumbrance) {
	this->actionEncumbrance = actionEncumbrance;
}

void ArmorObjectTemplate::setBlast(float blast) {
	this->blast = blast;
}

void ArmorObjectTemplate::setCold(float cold) {
	this->cold = cold;
}

void ArmorObjectTemplate::setElectricity(float electricity) {
	this->electricity = electricity;
}

void ArmorObjectTemplate::setEnergy(float energy) {
	this->energy = energy;
}

void ArmorObjectTemplate::setHealthEncumbrance(int healthEncumbrance) {
	this->healthEncumbrance = healthEncumbrance;
}

void ArmorObjectTemplate::setHeat(float heat) {
	this->heat = heat;
}

void ArmorObjectTemplate::setKinetic(float kinetic) {
	this->kinetic = kinetic;
}

void ArmorObjectTemplate::setLightSaber(float lightSaber) {
	this->lightSaber = lightSaber;
}

void ArmorObjectTemplate::setMindEncumbrance(int mindEncumbrance) {
	this->mindEncumbrance = mindEncumbrance;
}

void ArmorObjectTemplate::setRating(int rating) {
	this->rating = rating;
}

void ArmorObjectTemplate::setStun(float stun) {
	this->stun = stun;
}

void ArmorObjectTemplate::setHitLocation(int hitLocation) {
	this->hitLocation = hitLocation;
}

bool ArmorObjectTemplate::isArmorObjectTemplate() {
	return true;
}