#include "ImageDesignChangeMessageCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sessions/ImageDesignSession.h"

ImageDesignChangeMessageCallback::ImageDesignChangeMessageCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), designerID(0), targetID(0), tentID(0), type(0), objectControllerMain(objectControllerCallback) {
	setLoggingName("ImageDesignChangeMessageCallback");
}

void ImageDesignChangeMessageCallback::parse(Message* message) {
	message->shiftOffset(4); // ?Not sure this should be here.

	designerID = message->parseLong();
	targetID = message->parseLong();
	tentID = message->parseLong();
	type = message->parseByte();

	// info(true) << "designerID: " << designerID << "targetID: " << targetID << "Type: " << type;

	imageDesignData.parse(message);
}

void ImageDesignChangeMessageCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::IMAGEDESIGN);
	ManagedReference<ImageDesignSession*> session = dynamic_cast<ImageDesignSession*>(facade.get());

	if (session == nullptr)
		return;

	session->updateImageDesign(player, designerID, targetID, tentID, type, imageDesignData);
}