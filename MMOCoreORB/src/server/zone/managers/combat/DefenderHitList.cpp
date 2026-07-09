#include "DefenderHitList.h"

DefenderHitList::DefenderHitList() {
	defender = nullptr;
	hit = 0;
	hitLocation = 0;
	animationCRC = 0;
	initialDamage = 0;
	damageMultiplier = 0;
	foodMitigation = 0;
	jediMitigation = 0;
	forceFeedback = 0;
	forceAbsorb = 0;
	psgMitigation = 0;
	armorMitigation = 0;
}

DefenderHitList::~DefenderHitList() {
}

void DefenderHitList::setDefender(TangibleObject* tano) {
	defender = tano;
}

void DefenderHitList::setHit(int val) {
	hit = val;
}

void DefenderHitList::setHitLocation(int val) {
	hitLocation = val;
}

void DefenderHitList::setAnimationCRC(uint32 val) {
	animationCRC = val;
}

void DefenderHitList::setInitialDamage(int initDam) {
	initialDamage = initDam;
}

void DefenderHitList::setDamageMultiplier(float damageMulti) {
	damageMultiplier = damageMulti;
}

void DefenderHitList::setFoodMitigation(int fMit) {
	foodMitigation = fMit;
}

void DefenderHitList::setJediMitigation(int jediArmMit) {
	jediMitigation = jediArmMit;
}

void DefenderHitList::setForceFeedback(int feedbackDam) {
	forceFeedback = feedbackDam;
}

void DefenderHitList::setForceAbsorb(int amountAbsorbed) {
	forceAbsorb = amountAbsorbed;
}

void DefenderHitList::setPsgMitigation(int psgMit) {
	psgMitigation = psgMit;
}

void DefenderHitList::setArmorMitigation(int armorMit) {
	armorMitigation = armorMit;
}

void DefenderHitList::setPoolsToWound(const Vector<int>& woundPools) {
	poolsToWound = woundPools;
}

ManagedReference<TangibleObject*> DefenderHitList::getDefender() {
	return defender.get();
}

int DefenderHitList::getHit() {
	return hit;
}

int DefenderHitList::getHitLocation() {
	return hitLocation;
}

uint32 DefenderHitList::getAnimationCRC() {
	return animationCRC;
}

int DefenderHitList::getInitialDamage() {
	return initialDamage;
}

float DefenderHitList::getDamageMultiplier() {
	return damageMultiplier;
}

int DefenderHitList::getFoodMitigation() {
	return foodMitigation;
}

int DefenderHitList::getJediMitigation() {
	return jediMitigation;
}

int DefenderHitList::getForceFeedback() {
	return forceFeedback;
}

int DefenderHitList::getForceAbsorb() {
	return forceAbsorb;
}

int DefenderHitList::getPsgMitigation() {
	return psgMitigation;
}

int DefenderHitList::getArmorMitigation() {
	return armorMitigation;
}

const Vector<int>& DefenderHitList::getPoolsToWound() {
	return poolsToWound;
}