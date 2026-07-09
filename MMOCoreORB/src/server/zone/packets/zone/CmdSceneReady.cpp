#include "CmdSceneReady.h"

CmdSceneReady::CmdSceneReady() : BaseMessage(9) {
	insertShort(0x01);
	insertInt(0x43FD1C22);
}

void CmdSceneReady::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}