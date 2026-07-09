#include "GalaxyLoopTimes.h"

GalaxyLoopTimesResponse::GalaxyLoopTimesResponse() : BaseMessage() {
	insertShort(3);
	insertInt(0x4E428088);
	insertInt(0);
	insertInt(0);
	insertInt(0);
}

RequestGalaxyLoopTimesCallback::RequestGalaxyLoopTimesCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void RequestGalaxyLoopTimesCallback::parse(Message* message) {
}

void RequestGalaxyLoopTimesCallback::run() {
	// this makes the client spam the server with GalaxyLoopTimes requests
	// TODO: figure out the values in the Response

	/*GalaxyLoopTimesResponse* reply = new GalaxyLoopTimesResponse();
	client->sendMessage(reply);*/
}