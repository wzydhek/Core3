#include "LightsaberCrystalTuneSuiCallback.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/tangible/component/lightsaber/LightsaberCrystalComponent.h"

LightsaberCrystalTuneSuiCallback::LightsaberCrystalTuneSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void LightsaberCrystalTuneSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isMessageBox() || cancelPressed)
		return;

	SuiMessageBox* messageBox = cast<SuiMessageBox*>(sui);

	if (!creature->isPlayerCreature())
		return;

	if (!cancelPressed) {
		ManagedReference<LightsaberCrystalComponent*> crystal = cast<LightsaberCrystalComponent*>(sui->getUsingObject().get().get());

		crystal->tuneCrystal(creature);
	}
}