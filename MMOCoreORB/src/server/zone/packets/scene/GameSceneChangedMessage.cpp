#include "GameSceneChangedMessage.h"

GameSceneChangedMessage::GameSceneChangedMessage() : BaseMessage(8) {
	insertShort(0x01);
	insertInt(0xBBADAEB9);
}