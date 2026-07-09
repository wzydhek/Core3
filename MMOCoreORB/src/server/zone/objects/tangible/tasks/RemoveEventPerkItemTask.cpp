#include "RemoveEventPerkItemTask.h"

RemoveEventPerkItemTask::RemoveEventPerkItemTask(TangibleObject* obj) {
	tano = obj;
}

void RemoveEventPerkItemTask::run() {
	Reference<TangibleObject*> tano = this->tano.get();

	if (tano == nullptr) {
		return;
	}

	Locker locker(tano);

	if (tano->getServerObjectCRC() == 0x46BD798B) { // Jukebox
		Jukebox* jbox = tano.castTo<Jukebox*>();

		if (jbox != nullptr)
			jbox->stopPlaying();
	}

	tano->destroyObjectFromWorld(true);
	tano->destroyObjectFromDatabase();
}