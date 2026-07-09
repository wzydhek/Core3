#include "PingClient.h"

PingClient::PingClient(DatagramServiceThread* serv, Socket* sock, SocketAddress& addr) : BaseClientProxy(sock, addr) {
	setLoggingName("PingClient " + getFullIPAddress());
	setLogging(false);
	setLogLevel(Logger::FATAL);

	init(serv);
}

PingClient::~PingClient() {
}

void PingClient::disconnect(bool doLock) {
	if (isDisconnected())
		return;

	String time;
	Logger::getTime(time);

	StringBuffer msg;
	msg << time << " [PingServer] disconnecting client \'" << getFullIPAddress() << "\'\n";
	Logger::console.log(msg);

	BaseClientProxy::disconnect(doLock);
}

void PingClient::sendMessage(Message* msg) {
	BaseClientProxy::sendPacket(cast<BasePacket*>(msg));
}