#include "SkillBuffObjectAttributeListComponent.h"

void SkillBuffObjectAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const {
	Reference<SkillBuffTemplate*> skillBuff = cast<SkillBuffTemplate*>(object->getObjectTemplate());
	if (skillBuff == nullptr) {
		error("No SkillBuffTemplate for: " + String::valueOf(object->getServerObjectCRC()));
		return;
	}

	if (!object->isTangibleObject())
		return;

	// Already handled in tano.
	AttributeListComponent::fillAttributeList(alm, creature, object);

	/*ManagedReference<TangibleObject*> tano = cast<TangibleObject*>(object);
	if(tano->getUseCount() > 1)
		alm->insertAttribute("quantity", tano->getUseCount());*/

	VectorMap<String, float>* modifiers = skillBuff->getModifiers();

	for (int i = 0; i < modifiers->size(); ++i) {
		VectorMapEntry<String, float>* entry = &modifiers->elementAt(i);
		alm->insertAttribute("cat_skill_mod_bonus.@stat_n:" + entry->getKey(), (int)entry->getValue());
	}

	StringBuffer durationstring;
	int minutes = (int)floor(skillBuff->getDuration() / 60.0f);
	int seconds = skillBuff->getDuration() % 60;

	if (minutes > 0) {
		durationstring << minutes << "m ";
	}

	durationstring << seconds << "s";

	alm->insertAttribute("duration", durationstring.toString());
}