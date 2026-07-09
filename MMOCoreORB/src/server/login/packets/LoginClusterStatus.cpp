#include "LoginClusterStatus.h"

LoginClusterStatus::LoginClusterStatus(uint32 galcnt) : BaseMessage(100) {
	insertShort(0x03);
	insertInt(0x3436AEB6);

	insertInt(galcnt); // Zone Server List Count

	galaxyCount = galcnt;
}

LoginClusterStatus* LoginClusterStatus::clone() {
	LoginClusterStatus* pack = new LoginClusterStatus(galaxyCount);
	copy(pack, 0);

	pack->doSeq = doSeq;
	pack->doEncr = doEncr;
	pack->doComp = doComp;
	pack->doCRCTest = doCRCTest;

	return pack;
}

void LoginClusterStatus::addGalaxy(uint32 gid, const String& address, uint16 port, uint16 pingport) {
	insertInt(gid); // Zone Server ID

	insertAscii(address); // IP Address

	insertShort(port);	   // Zone Server Port
	insertShort(pingport); // Ping Server Port

	insertInt(100); // Population
	insertInt(0x00000CB2);
	insertInt(0x00000008);
	insertInt(0xFFFF8F80);
	insertInt(0x00000002); // status
	insertByte(0);
}

void LoginClusterStatus::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}