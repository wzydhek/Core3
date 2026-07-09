#include "PlayerMoneyResponseMessage.h"

PlayerMoneyResponseMessage::PlayerMoneyResponseMessage(CreatureObject* creo) : BaseMessage(20) {
	insertShort(0x03);
	insertInt(0x367E737E); // CRC

	insertInt(creo->getBankCredits());
	insertInt(creo->getCashCredits());
}