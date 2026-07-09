#include "LoginClient.h"

LoginClient::LoginClient(BaseClientProxy* session) : session(session) {
}

LoginClient::~LoginClient() {
}

void LoginClient::disconnect(bool doLock) {
	if (session == nullptr)
		return;

	if (session->isDisconnected())
		return;

	String time;
	Logger::getTime(time);

	Logger::console.log() << time << " [LoginServer] disconnecting client \'" << session->getIPAddress() << "\'\n";

	session->disconnect(doLock);
	accountID = -1;
}

String LoginClient::getIPAddress() const {
	if (session == nullptr)
		return "null-session";

	return session->getIPAddress();
}

void LoginClient::sendMessage(BasePacket* msg) {
	session->sendPacket(msg);
}

void LoginClient::sendErrorMessage(const String& title, const String& text, bool fatal, bool sendDisconnect) {
	ErrorMessage* errorMessage = new ErrorMessage(title, text, fatal);
	sendMessage(errorMessage);

	constexpr auto disconnectDelay = 500;

	if (sendDisconnect) {
		Core::getTaskManager()->scheduleTask(
			[session = WeakReference<BaseClientProxy*>(this->session)] {
				auto strongRef = session.get();

				if (strongRef) {
					strongRef->disconnect();
				}
			},
			"disconnectErrorTask", disconnectDelay);
	}
}

void LoginClient::info(const String& msg, bool doLog) const {
	session->info(msg, doLog);
}

LoggerHelper LoginClient::error() const {
	return session->error();
}

LoggerHelper LoginClient::info(bool val) const {
	return session->info(val);
}

LoggerHelper LoginClient::warning() const {
	return session->warning();
}

LoggerHelper LoginClient::debug() const {
	return session->debug();
}

ServiceClient* LoginClient::getSession() {
	return session;
}

const ServiceClient* LoginClient::getSession() const {
	return session;
}

uint32 LoginClient::getAccountID() const {
	return accountID;
}

void LoginClient::setAccountID(uint32 account) {
	LoginClient::accountID = account;
}

bool LoginClient::hasAccount() const {
	return (accountID != -1);
}