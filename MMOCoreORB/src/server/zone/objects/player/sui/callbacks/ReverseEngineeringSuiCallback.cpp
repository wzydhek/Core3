#include "ReverseEngineeringSuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"

ReverseEngineeringSuiCallback::ReverseEngineeringSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void ReverseEngineeringSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	if (creature == nullptr || sui == nullptr)
		return;

	ManagedReference<SceneObject*> obj = sui->getUsingObject().get();

	if (obj == nullptr || creature == nullptr) {
		return;
	}

	auto ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return;

	ManagedReference<SuiInputBox*> inputBox = new SuiInputBox(creature, SuiWindowType::OBJECT_NAME);

	inputBox->setUsingObject(obj);

	inputBox->setPromptTitle("@reverse_engineering_tool:title2"); // Name New Component
	inputBox->setPromptText("@reverse_engineering_tool:prompt2"); // That is a reserved name.

	inputBox->setMaxInputSize(20);

	inputBox->setCallback(new NameComponentSuiCallback(creature->getZoneServer()));
	inputBox->setForceCloseDistance(-1);

	ghost->addSuiBox(inputBox);

	creature->sendMessage(inputBox->generateMessage());
}