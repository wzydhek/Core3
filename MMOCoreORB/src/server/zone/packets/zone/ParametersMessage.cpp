#include "ParametersMessage.h"

ParametersMessage::ParametersMessage() : BaseMessage(7) {
	insertShort(0x02);
	insertInt(0x487652DA);
	insertInt(0x00000384);
}

void ParametersMessage::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}

ParametersMessageCallback::ParametersMessageCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), ackSequence(0) {
}

void ParametersMessageCallback::parse(Message* msg) {
	ackSequence = msg->parseShort();
}

void ParametersMessageCallback::execute() {
}