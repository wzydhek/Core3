#include "MountSpeedData.h"

MountSpeedData::MountSpeedData(String file, float run, float multiplier, int duration, int cooldown) : Object() {
	String filename = file;
	appearanceFilename.setValue(filename);

	runSpeed = run;
	gallopSpeedMultiplier = multiplier;
	gallopDuration = duration;
	gallopCooldown = cooldown;
}

MountSpeedData::~MountSpeedData() {
}

String MountSpeedData::getAppearanceFilename() {
	return appearanceFilename;
}

float MountSpeedData::getRunSpeed() {
	return runSpeed;
}

float MountSpeedData::getGallopSpeedMultiplier() {
	return gallopSpeedMultiplier;
}

int MountSpeedData::getGallopDuration() {
	return gallopDuration;
}

int MountSpeedData::getGallopCooldown() {
	return gallopCooldown;
}