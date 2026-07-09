#include "GamblingBet.h"

GamblingBet::GamblingBet(CreatureObject* pl, int bet, String betTarget) {
	player = pl;
	amount = bet;
	target = betTarget;
}

GamblingBet::GamblingBet(CreatureObject* pl, int bet) {
	player = pl;
	amount = bet;
	target = "slot";
}

int GamblingBet::getAmount() const {
	return amount;
}

const String& GamblingBet::getTarget() const {
	return target;
}

CreatureObject* GamblingBet::getPlayer() {
	return player.get();
}