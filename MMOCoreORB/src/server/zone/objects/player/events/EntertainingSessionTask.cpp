#include "EntertainingSessionTask.h"
#include "server/zone/objects/creature/CreatureObject.h"

EntertainingSessionTask::EntertainingSessionTask(EntertainingSession* sess) {
	session = sess;
}

void EntertainingSessionTask::run() {
	ManagedReference<EntertainingSession*> strongRef = session.get();

	if (strongRef == nullptr)
		return;

	strongRef->activateAction();
}