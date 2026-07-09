#include "PlayerTeachSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/managers/skill/SkillManager.h"
#include "server/zone/managers/player/PlayerManager.h"

PlayerTeachSuiCallback::PlayerTeachSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void PlayerTeachSuiCallback::run(CreatureObject* teacher, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || cancelPressed || args->size() <= 0)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(sui);

	if (listBox->getMenuSize() <= index || index < 0)
		return;

	ManagedReference<SceneObject*> usingObject = listBox->getUsingObject().get();

	if (usingObject == nullptr || !usingObject->isCreatureObject())
		return;

	CreatureObject* student = cast<CreatureObject*>(usingObject.get());

	Locker _lock(student, teacher);

	Skill* skill = SkillManager::instance()->getSkill(listBox->getMenuObjectID(index));

	PlayerManager* playerManager = server->getPlayerManager();
	playerManager->offerTeaching(teacher, student, skill);
}