#include "SelectDroidEffectSuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidEffectsModuleDataComponent.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

SelectDroidEffectSuiCallback::SelectDroidEffectSuiCallback(ZoneServer* serv, DroidEffectsModuleDataComponent* module, int slotIndex) : SuiCallback(serv) {
	this->module = module;
	this->slotIndex = slotIndex;
}

void SelectDroidEffectSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || module == nullptr)
		return;

	if (cancelPressed) {
		return;
	}

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);
	String effectName = listBox->getMenuItemName(index);

	// If empty slot is configured, remove the configured effect
	if (effectName.contains("empty_slot")) {
		Locker dlock(module->getDroidObject(), player);
		module->setEffect(effectName, -1, slotIndex);
		player->sendSystemMessage("Effect successfully removed from slot " + String::valueOf(slotIndex + 1));
	}
	// Otherwise prompt for delay
	else {
		ManagedReference<SuiInputBox*> box = new SuiInputBox(player, SuiWindowType::SELECT_DROID_EFFECT_DELAY);
		box->setCallback(new SelectDroidEffectDelaySuiCallback(player->getZoneServer(), module, effectName, slotIndex));
		box->setPromptTitle("@pet/droid_modules:effects_set_up"); // Configure Effects
		box->setPromptText("Enter a delay between 3 and 60 seconds.  The next effect will be executed after this delay.");
		box->setMaxInputSize(2);
		box->setDefaultInput("15");
		box->setOkButton(true, "@ok");
		box->setCancelButton(true, "@cancel");

		box->setUsingObject(module->getDroidObject());
		player->getPlayerObject()->addSuiBox(box);
		player->sendMessage(box->generateMessage());
	}
}