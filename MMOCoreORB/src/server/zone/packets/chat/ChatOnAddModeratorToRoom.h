/*
 * ChatOnAddModeratorToRoom.h
 *
 *  Created on: Feb 16, 2016
 *      Author: Anakis
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneServer.h"

class ChatOnAddModeratorToRoom : public BaseMessage {
public:
	ChatOnAddModeratorToRoom(CreatureObject* oper, const String& opeeName, const String& roomPath, int error, int requestID = 0) : BaseMessage() {
		String galaxy = oper->getZoneServer()->getGalaxyName();

		insertShort(0x06);
		insertInt(0x36A03858);  //Opcode

		insertAscii("SWG"); //Game
		insertAscii(galaxy); //Galaxy name
		insertAscii(opeeName); //First name of player to be op'd

		insertAscii("SWG"); //Game
		insertAscii(galaxy); // Galaxy name
		insertAscii(oper->getFirstName()); //First name of player who sent the command

		insertInt(error); ///Result code

		insertAscii(roomPath); //Full room path

		insertInt(requestID); //Request ID

	}

};
