#include "AreaTrackSuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

AreaTrackSuiCallback::AreaTrackSuiCallback(ZoneServer* serv, const String& name) : SuiCallback(serv) {
	nodeName = name;
}

void AreaTrackSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || cancelPressed)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(sui);

	if (!creature->isPlayerCreature())
		return;

	if (!cancelPressed) {
		int index = Integer::valueOf(args->get(0).toString());

		if (index < 0 || index > 2)
			return;

		if (server != nullptr) {
			uint64 objectID = creature->getObjectID();
			Emote* emsg = new Emote(objectID, objectID, 0, 72, true, false);
			creature->broadcastMessage(emsg, true);
			creature->sendSystemMessage("@skl_use:sys_scan_begin"); // You begin to examine the environment for information.

			Reference<AreaTrackTask*> att = new AreaTrackTask(creature, index);
			creature->addPendingTask("areatrack", att, 6000);
			creature->addCooldown("areatrack", 6000);
		}
	}
}