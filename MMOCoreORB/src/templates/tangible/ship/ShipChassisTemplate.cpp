#include "ShipChassisTemplate.h"

ShipChassisTemplate::ShipChassisTemplate() {
	chassisDeed = "";
	certificationRequired = "";

	dealerFee = 0;
	pob = false;
}

ShipChassisTemplate::~ShipChassisTemplate() {
}

void ShipChassisTemplate::readObject(LuaObject* templateData) {
	ShipComponentTemplate::readObject(templateData);

	chassisDeed = templateData->getStringField("chassisDeed");
	certificationRequired = templateData->getStringField("certificationRequired");

	auto skillTable = templateData->getObjectField("skillRequired");

	if (skillTable.isValidTable()) {
		for (int i = 1; i <= skillTable.getTableSize(); ++i) {
			auto skillString = skillTable.getStringAt(i);

			skillsRequired.add(skillString);
		}
	}

	skillTable.pop();

	dealerFee = templateData->getIntField("dealerFee");
	pob = templateData->getBooleanField("pob");
}

// Accessors
String ShipChassisTemplate::getChassisDeed() {
	return chassisDeed;
}

String ShipChassisTemplate::getCertificationsRequired() {
	return certificationRequired;
}

int ShipChassisTemplate::getTotalSkillsRequired() {
	return skillsRequired.size();
}

String ShipChassisTemplate::getSkillRequired(int index) {
	return skillsRequired.get(index);
}

int ShipChassisTemplate::getDealerFee() {
	return dealerFee;
}

bool ShipChassisTemplate::isPob() {
	return pob;
}

bool ShipChassisTemplate::isShipChassisTemplate() {
	return true;
}