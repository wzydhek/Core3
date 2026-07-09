#include "NameNpcActorSuiCallback.h"

NameNpcActorSuiCallback::NameNpcActorSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void NameNpcActorSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isInputBox() || args->size() < 1) {
		clearSession(player);
		return;
	}

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::NPCACTORCREATION);

	if (facade == nullptr) {
		clearSession(player);
		return;
	}

	ManagedReference<NpcActorCreationSession*> npcActorSession = dynamic_cast<NpcActorCreationSession*>(facade.get());

	if (npcActorSession == nullptr) {
		clearSession(player);
		return;
	}

	if (cancelPressed) {
		npcActorSession->cancelSession();
		clearSession(player);
		return;
	}

	String name = args->get(0).toString();

	npcActorSession->createNpcActor(name);
}

void NameNpcActorSuiCallback::clearSession(CreatureObject* player) {
	Locker lock(player);

	player->dropActiveSession(SessionFacadeType::NPCACTORCREATION);
}