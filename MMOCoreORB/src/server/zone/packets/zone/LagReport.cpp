#include "LagReport.h"

GameServerLagResponse::GameServerLagResponse() : BaseMessage() {
	insertShort(1); // figure out
	insertInt(0x789A4E0A);
}

ConnectionServerLagResponse::ConnectionServerLagResponse() : BaseMessage() {
	insertShort(1); // figure out
	insertInt(0x1590F63C);
}

LagReportCallback::LagReportCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), connectionServerLag(0), gameServerLag(0) {
}

void LagReportCallback::parse(Message* message) {
	connectionServerLag = message->parseInt();
	gameServerLag = message->parseInt();
}

void LagReportCallback::run() {
}

LagRequestCallback::LagRequestCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void LagRequestCallback::parse(Message* message) {
}

void LagRequestCallback::run() {
	ManagedReference<ZoneClientSession*> session = client.get();

	if (session == nullptr)
		return;

	ConnectionServerLagResponse* connectionServer = new ConnectionServerLagResponse();
	session->sendMessage(connectionServer);

	GameServerLagResponse* gameServer = new GameServerLagResponse();
	session->sendMessage(gameServer);
}