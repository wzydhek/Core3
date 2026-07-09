#include "SuiCallback.h"

SuiCallback::SuiCallback(ZoneServer* serv) {
	server = serv;
}

void LambdaSuiCallback::run(server::zone::objects::creature::CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	return function.getLambda()(player, suiBox, eventIndex, args);
}