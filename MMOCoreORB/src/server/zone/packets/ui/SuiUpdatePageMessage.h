#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/player/sui/SuiPageData.h"

class SuiUpdatePageMessage : public BaseMessage {

public:
	SuiUpdatePageMessage(SuiPageData* sui);
};
