#include "ImageDesignRejectMessageCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sessions/ImageDesignSession.h"

ImageDesignRejectMessageCallback::ImageDesignRejectMessageCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), designer(0), target(0), tent(0), type(0), objectControllerMain(objectControllerCallback) {
}

void ImageDesignRejectMessageCallback::parse(Message* message) {
	message->shiftOffset(4); //?
	designer = message->parseLong();
	target = message->parseLong();
	tent = message->parseLong();
	type = message->parseByte();

	data.parse(message);
}

void ImageDesignRejectMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::IMAGEDESIGN);
	ManagedReference<ImageDesignSession*> session = dynamic_cast<ImageDesignSession*>(facade.get());

	if (session == nullptr)
		return;

	session->cancelImageDesign(designer, target, tent, type, data);
}