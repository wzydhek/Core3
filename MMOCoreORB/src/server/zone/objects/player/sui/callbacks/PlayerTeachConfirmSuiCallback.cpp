#include "PlayerTeachConfirmSuiCallback.h"
#include "server/zone/managers/player/PlayerManager.h"

PlayerTeachConfirmSuiCallback::PlayerTeachConfirmSuiCallback(ZoneServer* serv, Skill* skl) : SuiCallback(serv) {
	skill = skl;
}

void PlayerTeachConfirmSuiCallback::run(CreatureObject* student, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<SceneObject*> usingObject = sui->getUsingObject().get();

	if (usingObject == nullptr || !usingObject->isCreatureObject())
		return;

	CreatureObject* teacher = cast<CreatureObject*>(usingObject.get());

	if (cancelPressed) {
		StringIdChatParameter params("teaching", "offer_refused"); //%TT has refused your offer to teach.
		params.setTT(student->getDisplayedName());
		teacher->sendSystemMessage(params);
		return;
	}

	Locker _lock(teacher, student);

	PlayerManager* playerManager = server->getPlayerManager();
	playerManager->acceptTeachingOffer(teacher, student, skill.get());
}