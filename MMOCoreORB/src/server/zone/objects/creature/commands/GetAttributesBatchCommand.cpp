#include "GetAttributesBatchCommand.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/Zone.h"

GetAttributesBatchCommand::GetAttributesBatchCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GetAttributesBatchCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return GENERALERROR;

	StringTokenizer ids(arguments.toString());

	Zone* zone = creature->getZone();

	if (zone == nullptr)
		return GENERALERROR;

	int incr = 0;

	while (ids.hasMoreTokens()) {
		uint64 objid = 0;

		try {
			objid = ids.getLongToken();

		} catch (Exception& e) {
			error(e.getMessage());
		}

		if (objid == 0)
			continue;

		ManagedReference<SceneObject*> object = zone->getZoneServer()->getObject(objid);

		if (object != nullptr) {
			ManagedReference<SceneObject*> parent = object->getParent().get();

			if (parent != nullptr && parent->isCreatureObject() && !ghost->isPrivileged() && !object->isASubChildOf(creature)) {
				sendEmptyAttributes(creature, objid);
			} else {
				int count = (incr == 0 && !ids.hasMoreTokens()) ? 0 : incr;

				sendAttributes(creature, object, count);
			}

		} else {
			sendEmptyAttributes(creature, objid);
		}

		if (++incr > MAXIMUM_BATCH) {
			creature->error() << creature->getDisplayedName() << " ID: " << creature->getObjectID() << "  GetAttributesBatchCommand -- Objects attribute limit exceeded with more than " << incr << " total objects.";

			return GENERALERROR;
		}
	}

	return SUCCESS;
}

void GetAttributesBatchCommand::sendEmptyAttributes(CreatureObject* creature, uint64 objid) const {
	AttributeListMessage* msg = new AttributeListMessage(objid);
	creature->sendMessage(msg);
}

void GetAttributesBatchCommand::sendAttributes(CreatureObject* creature, SceneObject* object, int incr) const {
	object->sendAttributeListTo(creature);

	creature->notifyObservers(ObserverEventType::GETATTRIBUTESBATCHCOMMAND, object, incr);
}