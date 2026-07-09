#include "HeroRingAttributeListComponent.h"

void HeroRingAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const {
	if (object == nullptr || creature == nullptr || alm == nullptr)
		return;

	ManagedReference<TangibleObject*> tano = cast<TangibleObject*>(object);

	HeroRingDataComponent* data = cast<HeroRingDataComponent*>(tano->getDataObjectComponent()->get());

	if (data == nullptr || !data->isHeroRingData())
		return;

	int maxCond = tano->getMaxCondition();

	StringBuffer cond;
	cond << (maxCond - (int)tano->getConditionDamage()) << "/" << maxCond;
	alm->insertAttribute("condition", cond);
	alm->insertAttribute("volume", 1);

	int charges = data->getCharges();

	alm->insertAttribute("effect", "@quest/hero_of_tatooine/system_messages:restore");
	alm->insertAttribute("charges", charges);

	if (!creature->checkCooldownRecovery("mark_of_hero")) {
		const Time* timeRemaining = creature->getCooldownTime("mark_of_hero");
		alm->insertAttribute("time_remaining", getCooldownString(timeRemaining->miliDifference() * -1));
	}
}

String HeroRingAttributeListComponent::getCooldownString(uint32 delta) {
	int seconds = delta / 1000;

	int hours = seconds / 3600;
	seconds -= hours * 3600;

	int minutes = seconds / 60;
	seconds -= minutes * 60;

	StringBuffer buffer;

	if (hours > 0)
		buffer << hours << "h ";

	if (minutes > 0)
		buffer << minutes << "m ";

	if (seconds > 0)
		buffer << seconds << "s";

	return buffer.toString();
}