#include "DnaSampleTemplate.h"

DnaSampleTemplate::DnaSampleTemplate() {
	cleverness = 0.f;
	endurance = 0.f;
	fierceness = 0.f;
	power = 0.f;
	intellect = 0.f;
	courage = 0.f;
	dependability = 0.f;
	dexterity = 0.f;
	fortitude = 0.f;
	hardiness = 0.f;

	source = "unknown";
	ranged = false;
	special1 = "";
	special2 = "";
	quality = "Low";
	armorRating = 0;
	kinResist = -1;
	energyResist = -1;
	blastResist = -1;
	coldResist = -1;
	heatResist = -1;
	elecResist = -1;
	acidResist = -1;
	stunResist = -1;
	saberResist = -1;
}

DnaSampleTemplate::~DnaSampleTemplate() {
}

void DnaSampleTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	quality = templateData->getStringField("quality");
}

float DnaSampleTemplate::getAcidResist() const {
	return acidResist;
}

float DnaSampleTemplate::getSaberResist() const {
	return saberResist;
}

int DnaSampleTemplate::getArmorRating() const {
	return armorRating;
}

float DnaSampleTemplate::getBlastResist() const {
	return blastResist;
}

float DnaSampleTemplate::getCleverness() const {
	return cleverness;
}

float DnaSampleTemplate::getColdResist() const {
	return coldResist;
}

float DnaSampleTemplate::getCourage() const {
	return courage;
}

float DnaSampleTemplate::getDependability() const {
	return dependability;
}

float DnaSampleTemplate::getDexterity() const {
	return dexterity;
}

float DnaSampleTemplate::getElecResist() const {
	return elecResist;
}

float DnaSampleTemplate::getEndurance() const {
	return endurance;
}

float DnaSampleTemplate::getEnergyResist() const {
	return energyResist;
}

float DnaSampleTemplate::getFierceness() const {
	return fierceness;
}

float DnaSampleTemplate::getFortitude() const {
	return fortitude;
}

float DnaSampleTemplate::getHardiness() const {
	return hardiness;
}

float DnaSampleTemplate::getHeatResist() const {
	return heatResist;
}

float DnaSampleTemplate::getIntellect() const {
	return intellect;
}

float DnaSampleTemplate::getKinResist() const {
	return kinResist;
}

float DnaSampleTemplate::getPower() const {
	return power;
}

String DnaSampleTemplate::getQuality() const {
	return quality;
}

bool DnaSampleTemplate::getRanged() const {
	return ranged;
}

String DnaSampleTemplate::getSource() const {
	return source;
}

String DnaSampleTemplate::getSpecial1() const {
	return special1;
}

String DnaSampleTemplate::getSpecial2() const {
	return special2;
}

float DnaSampleTemplate::getStunResist() const {
	return stunResist;
}

void DnaSampleTemplate::setAcidResist(float acidResist) {
	this->acidResist = acidResist;
}

void DnaSampleTemplate::setSaberResist(float value) {
	this->saberResist = value;
}

void DnaSampleTemplate::setArmorRating(int armorRating) {
	this->armorRating = armorRating;
}

void DnaSampleTemplate::setBlastResist(float blastResist) {
	this->blastResist = blastResist;
}

void DnaSampleTemplate::setCleverness(float cleverness) {
	this->cleverness = cleverness;
}

void DnaSampleTemplate::setColdResist(float coldResist) {
	this->coldResist = coldResist;
}

void DnaSampleTemplate::setCourage(float courage) {
	this->courage = courage;
}

void DnaSampleTemplate::setDependability(float dependability) {
	this->dependability = dependability;
}

void DnaSampleTemplate::setDexterity(float dexterity) {
	this->dexterity = dexterity;
}

void DnaSampleTemplate::setElecResist(float elecResist) {
	this->elecResist = elecResist;
}

void DnaSampleTemplate::setEndurance(float endurance) {
	this->endurance = endurance;
}

void DnaSampleTemplate::setEnergyResist(int energyResist) {
	this->energyResist = energyResist;
}

void DnaSampleTemplate::setFierceness(float fierceness) {
	this->fierceness = fierceness;
}

void DnaSampleTemplate::setFortitude(float fortitude) {
	this->fortitude = fortitude;
}

void DnaSampleTemplate::setHardiness(float hardiness) {
	this->hardiness = hardiness;
}

void DnaSampleTemplate::setHeatResist(float heatResist) {
	this->heatResist = heatResist;
}

void DnaSampleTemplate::setIntellect(float intellect) {
	this->intellect = intellect;
}

void DnaSampleTemplate::setKinResist(float kinResist) {
	this->kinResist = kinResist;
}

void DnaSampleTemplate::setPower(float power) {
	this->power = power;
}

void DnaSampleTemplate::setQuality(String quality) {
	this->quality = quality;
}

void DnaSampleTemplate::setRanged(bool ranged) {
	this->ranged = ranged;
}

void DnaSampleTemplate::setSource(String source) {
	this->source = source;
}

void DnaSampleTemplate::setSpecial1(String special1) {
	this->special1 = special1;
}

void DnaSampleTemplate::setSpecial2(String special2) {
	this->special2 = special2;
}

void DnaSampleTemplate::setStunResist(float stunResist) {
	this->stunResist = stunResist;
}

bool DnaSampleTemplate::isDnaSampleTemplate() {
	return true;
}