#include "ShipObjectMessage3.h"
#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"
#include "server/zone/managers/stringid/StringIdManager.h"

ShipObjectMessage3::ShipObjectMessage3(ShipObject* ship) : BaseLineMessage(ship, 0x53484950, 3, 22) {
	insertFloat(ship->getComplexity());
	insertStringId(ship->getObjectName());

	insertUnicode(getShipName(ship));

	insertInt(ship->getVolume());

	String app;
	ship->getCustomizationString(app);
	insertAscii(app);

	auto visibleComponents = ship->getVisibleComponents();
	visibleComponents->insertToMessage(this);

	insertInt(ship->getOptionsBitmask());
	insertInt(ship->getUseCount());
	insertInt(ship->getConditionDamage());
	insertInt(ship->getMaxCondition());
	insertByte(ship->getObjectVisible());

	insertFloat(ship->getSlip());
	insertFloat(ship->getChassisCurrentHealth());
	insertFloat(ship->getChassisMaxHealth());

	insertInt(ship->getShipNameCRC());

	ship->getMaxArmorMap()->insertToMessage(this);
	ship->getCurrentArmorMap()->insertToMessage(this);
	ship->getCurrentHitpointsMap()->insertToMessage(this);
	ship->getMaxHitpointsMap()->insertToMessage(this);
	ship->getComponentOptionsMap()->insertToMessage(this);

	insertFloat(ship->getMaxFrontShield());
	insertFloat(ship->getMaxRearShield());

	setSize();
}

UnicodeString ShipObjectMessage3::getShipName(ShipObject* ship) {
	if (!ship->isShipAiAgent()) {
		return ship->getShipLaunchedName();
	}

	auto shipAgent = ship->asShipAiAgent();

	if (shipAgent != nullptr) {
		String stfShip = "@space/ship_names:" + shipAgent->getShipAgentTemplateName();
		return StringIdManager::instance()->getStringId(stfShip.hashCode());
	}

	return "";
}