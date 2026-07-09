#include "SharedInstallationObjectTemplate.h"

SharedInstallationObjectTemplate::SharedInstallationObjectTemplate() {
	installationType = 0;

	armorRating = 0;
	kinetic = 0;
	energy = 0;
	electricity = 0;
	stun = 0;
	blast = 0;
	heat = 0;
	cold = 0;
	acid = 0;
	lightSaber = 0;
	weapon = "";
	chanceHit = 0;
	factionString = "";
}

SharedInstallationObjectTemplate::~SharedInstallationObjectTemplate() {
}

void SharedInstallationObjectTemplate::readObject(LuaObject* templateData) {
	SharedStructureObjectTemplate::readObject(templateData);

	installationType = templateData->getIntField("installationType");

	armorRating = templateData->getIntField("rating");
	kinetic = templateData->getFloatField("kinetic");
	energy = templateData->getFloatField("energy");
	electricity = templateData->getFloatField("electricity");
	stun = templateData->getFloatField("stun");
	blast = templateData->getFloatField("blast");
	heat = templateData->getFloatField("heat");
	cold = templateData->getFloatField("cold");
	acid = templateData->getFloatField("acid");
	lightSaber = templateData->getFloatField("lightSaber");
	weapon = templateData->getStringField("weapon");
	chanceHit = templateData->getFloatField("chanceHit");
	factionString = templateData->getStringField("factionString");
}

void SharedInstallationObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SIOT') {
		// Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedTangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SIOT');

	uint32 derv = iffStream->getNextFormType();

	if (derv == 'DERV') {
		loadDerv(iffStream);

		derv = iffStream->getNextFormType();
	}

	/*while (derv != 0) {
						if (derv != '
					}*/

	iffStream->openForm(derv);

	try {
		// parseFileData(iffStream);
	} catch (Exception& e) {
		String msg;
		msg += "exception caught parsing file data ->";
		msg += e.getMessage();

		Logger::console.error(msg);
	}

	iffStream->closeForm(derv);

	if (iffStream->getRemainingSubChunksNumber() > 0) {
		readObject(iffStream);
	}

	iffStream->closeForm('SIOT');
}

bool SharedInstallationObjectTemplate::isSharedInstallationObjectTemplate() {
	return true;
}

uint32 SharedInstallationObjectTemplate::getInstallationType() const {
	return installationType;
}

unsigned int SharedInstallationObjectTemplate::getArmorRating() const {
	return armorRating;
}

float SharedInstallationObjectTemplate::getKinetic() const {
	return kinetic;
}

float SharedInstallationObjectTemplate::getEnergy() const {
	return energy;
}

float SharedInstallationObjectTemplate::getElectricity() const {
	return electricity;
}

float SharedInstallationObjectTemplate::getStun() const {
	return stun;
}

float SharedInstallationObjectTemplate::getBlast() const {
	return blast;
}

float SharedInstallationObjectTemplate::getHeat() const {
	return heat;
}

float SharedInstallationObjectTemplate::getCold() const {
	return cold;
}

float SharedInstallationObjectTemplate::getAcid() const {
	return acid;
}

float SharedInstallationObjectTemplate::getLightSaber() const {
	return lightSaber;
}

const String& SharedInstallationObjectTemplate::getWeapon() const {
	return weapon;
}

float SharedInstallationObjectTemplate::getChanceHit() const {
	return chanceHit;
}

const String& SharedInstallationObjectTemplate::getFactionString() const {
	return factionString;
}