#include "LoginMessageProcessorTask.h"
#include "server/login/LoginServer.h"

LoginMessageProcessorTask::LoginMessageProcessorTask(Message* msg, LoginPacketHandler* handler) {
	message = msg;

	packetHandler = handler;
}

LoginMessageProcessorTask::~LoginMessageProcessorTask() {
}

void LoginMessageProcessorTask::run() {
	static Logger logger("LoginMessageProcessorTask", Logger::INFO);

	try {
		message->reset();

		packetHandler->handleMessage(message);
	} catch (const PacketIndexOutOfBoundsException& e) {
		logger.error() << e.getMessage();

		logger.debug() << "incorrect packet - " << *message;
	} catch (const Exception& e) {
		logger.error() << e.getMessage();

		logger.debug() << "incorrect packet - " << *message;
	}
}