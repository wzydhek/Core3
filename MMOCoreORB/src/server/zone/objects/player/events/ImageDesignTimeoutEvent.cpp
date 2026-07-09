#include "ImageDesignTimeoutEvent.h"

ImageDesignTimeoutEvent::ImageDesignTimeoutEvent(ImageDesignSession* session) {
	idSession = session;
}

void ImageDesignTimeoutEvent::run() {
	ManagedReference<ImageDesignSession*> session = idSession.get();

	if (session == nullptr)
		return;

	session->sessionTimeout();
}