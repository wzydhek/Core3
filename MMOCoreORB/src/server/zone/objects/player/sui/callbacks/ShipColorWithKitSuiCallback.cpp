#include "ShipColorWithKitSuiCallback.h"
#include "server/zone/objects/player/sui/SuiBox.h"

ShipColorWithKitSuiCallback::ShipColorWithKitSuiCallback(ZoneServer* serv, ShipPaintKit* kit) : SuiCallback(serv), customizationKit(kit) {
}

void ShipColorWithKitSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<ShipPaintKit*> kit = customizationKit.get();

	if (creature == nullptr || kit == nullptr || cancelPressed || args->size() == 0)
		return;

	ManagedReference<TangibleObject*> ship = sui->getUsingObject().castTo<TangibleObject*>();

	if (ship == nullptr || !ship->isShipObject())
		return;

	Locker kitLocker(kit);
	Locker shipLocker(ship, kit);

	String varKey = sui->getPromptTitle();

	if (varKey == "/shared_owner/index_color_1") {
		if (kit->getPrimaryUsed())
			return;

		kit->setPrimaryUsed(true);
	} else if (varKey == "/shared_owner/index_color_2") {
		if (kit->getSecondaryUsed())
			return;

		kit->setSecondaryUsed(true);
	}

	int colorIndex = Integer::valueOf(args->get(0).toString());

	ship->setCustomizationVariable(varKey, colorIndex, true);

	if (kit->getPrimaryUsed() && kit->getSecondaryUsed()) {
		kit->destroyObjectFromWorld(true);
		kit->destroyObjectFromDatabase(true);
	}
}