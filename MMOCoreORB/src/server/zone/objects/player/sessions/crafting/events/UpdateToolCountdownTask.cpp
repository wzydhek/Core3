#include "UpdateToolCountdownTask.h"

UpdateToolCountdownTask::UpdateToolCountdownTask(CreatureObject* pl, TangibleObject* tool, int time) : Task() {
	craftTool = tool;
	player = pl;
	timeLeft = time;
}

void UpdateToolCountdownTask::run() {
	try {
		ManagedReference<CreatureObject*> crafter = player.get();

		if (crafter == nullptr) {
			return;
		}

		Locker locker(crafter);

		ManagedReference<TangibleObject*> craftingTool = craftTool.get();

		if (craftingTool == nullptr) {
			return;
		}

		Locker clocker(craftingTool, crafter);

		craftingTool->setCountdownTimer(timeLeft, true);

	} catch (Exception& e) {
		System::out << "Unreported exception caught in UpdateToolCountdownEvent::activate\n";
	}
}