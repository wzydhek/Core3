#include "InjuryTreatmentTask.h"

InjuryTreatmentTask::InjuryTreatmentTask(CreatureObject* creo, const StringIdChatParameter& msg, const String& task) {
	creature = creo;
	message = msg;
	pendingTask = task;
}

void InjuryTreatmentTask::run() {
	Locker locker(creature);

	creature->removePendingTask(pendingTask);
	// creature->sendSystemMessage("@healing_response:healing_response_58"); //You are now ready to heal more damage.
	creature->sendSystemMessage(message);
}