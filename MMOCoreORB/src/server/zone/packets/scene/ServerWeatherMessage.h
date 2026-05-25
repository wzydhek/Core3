/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ServerWeatherMessage : public BaseMessage {
public:
	ServerWeatherMessage(int weather, float windx, float windMag, float windy) : BaseMessage() {

		insertShort(0x03);
		insertInt(0x486356EA);
		insertInt(weather);

		insertFloat(windx);
		insertFloat(windMag);
		insertFloat(windy);

	}

};
