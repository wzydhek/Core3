/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * \file ImageDesignTimeoutEvent.h
 * \author Polonel
 * \date 02.07.2011
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/player/sessions/ImageDesignSession.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class ImageDesignTimeoutEvent: public Task {
	ManagedWeakReference<ImageDesignSession*> idSession;

public:
	ImageDesignTimeoutEvent(ImageDesignSession* session);

	void run();

};

}
}
}
}
}
