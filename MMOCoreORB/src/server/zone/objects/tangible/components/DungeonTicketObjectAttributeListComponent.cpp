#include "DungeonTicketObjectAttributeListComponent.h"

void DungeonTicketObjectAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const {
	ManagedReference<TangibleObject*> tano = cast<TangibleObject*>(object);

	TicketObject* ticketObject = tano.castTo<TicketObject*>();

	String dep = ticketObject->getDeparturePlanet();
	String point = ticketObject->getDeparturePoint();
	String arrive = ticketObject->getArrivalPoint();

	alm->insertAttribute("travel_departure_planet", "@planet_n:" + dep);
	alm->insertAttribute("travel_departure_point", "@dungeon/space_dungeon:corvette_" + point + "_pilot");
	alm->insertAttribute("travel_arrival_point", "@dungeon/space_dungeon:corvette_" + arrive);
}