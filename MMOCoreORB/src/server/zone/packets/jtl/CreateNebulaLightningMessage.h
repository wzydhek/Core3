/*
 * CreateNebulaLightningMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "engine/util/u3d/Vector3.h"

class CreateNebulaLightningMessage : public BaseMessage {
public:
	CreateNebulaLightningMessage(uint16 lightningCount, int nebulaID, int startMili, int endMili, Vector3 startPoint, Vector3 endPoint);
};
