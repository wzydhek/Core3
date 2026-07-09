#include "LoginEnumCluster.h"

LoginEnumCluster::LoginEnumCluster(uint32 galcnt) : BaseMessage(100) {
	insertShort(0x02);
	insertInt(0xC11C63B9);

	insertInt(galcnt); // Galaxy count

	galaxyCount = galcnt;
}

LoginEnumCluster* LoginEnumCluster::clone() {
	LoginEnumCluster* pack = new LoginEnumCluster(galaxyCount);
	copy(pack, 0);

	pack->doSeq = doSeq;
	pack->doEncr = doEncr;
	pack->doComp = doComp;
	pack->doCRCTest = doCRCTest;

	return pack;
}

void LoginEnumCluster::addGalaxy(uint32 gid, const String& name) {
	insertInt(gid); // Zone Server ID

	insertAscii(name); // IP Address

	insertInt(0xFFFF8F80);
}

void LoginEnumCluster::finish() {
	insertInt(0x00000008);
}

void LoginEnumCluster::parse(Packet* pack) {
	uint16 ackSequence = pack->parseShort();
}