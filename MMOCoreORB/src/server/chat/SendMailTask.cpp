#include "SendMailTask.h"

SendMailTask::SendMailTask(CreatureObject* receiver, PersistentMessage* mail, const UnicodeString& sender) {
	this->receiver = receiver;
	this->mail = mail;
	senderName = sender;
}

void SendMailTask::run() {
	Locker locker(receiver);

	PlayerObject* ghost = receiver->getPlayerObject();

	ghost->addPersistentMessage(mail->getObjectID());

	if (receiver->isOnline())
		mail->sendTo(receiver, false);
}