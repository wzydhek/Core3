#include "ChannelForceBuffTickEvent.h"

ChannelForceBuffTickEvent::ChannelForceBuffTickEvent(ChannelForceBuff* buff) : Task() {
	buffObject = buff;
}

void ChannelForceBuffTickEvent::run() {
	ManagedReference<ChannelForceBuff*> buff = buffObject.get();

	if (buff == nullptr)
		return;

	Locker locker(buff);

	buff->doHamTick();
}