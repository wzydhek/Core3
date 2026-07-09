#include "ServerWeatherMessage.h"

ServerWeatherMessage::ServerWeatherMessage(int weather, float windx, float windMag, float windy) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x486356EA);
	insertInt(weather);

	insertFloat(windx);
	insertFloat(windMag);
	insertFloat(windy);
}