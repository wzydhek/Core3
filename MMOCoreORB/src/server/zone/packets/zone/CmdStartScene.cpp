#include "CmdStartScene.h"
#include "server/zone/Zone.h"
#include "server/zone/SpaceZone.h"
#include "templates/manager/TemplateManager.h"

CmdStartScene::CmdStartScene(CreatureObject* creo) : BaseMessage(50) {
	Zone* zone = creo->getZone();

	if (zone == nullptr) {
		creo->error() << "Zone is null in CmdStartScene";
		return;
	}

	insertShort(0x09);
	insertInt(0x3AE6DFAE);
	insertByte(0);
	insertLong(creo->getObjectID());
	insertAscii("terrain/" + zone->getZoneName() + ".trn"); // terrain name

	Vector3 worldPosition = creo->getWorldPosition();

	insertFloat(worldPosition.getX()); // X
	insertFloat(worldPosition.getZ()); // Z
	insertFloat(worldPosition.getY()); // Y

	uint32 crc = creo->getClientObjectCRC();
	String file = TemplateManager::instance()->getTemplateFile(crc);
	insertAscii(file);

	insertLong(zone->getGalacticTime()); // galactic time
}

void CmdStartScene::parse(Packet* pack) {
}