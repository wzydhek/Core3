#include "XpPurchaseAttributeListComponent.h"

void XpPurchaseAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const {
	XpPurchaseTemplate* templateData = cast<XpPurchaseTemplate*>(object->getObjectTemplate());
	if (templateData == nullptr) {
		return;
	}

	StringIdManager* stringIdManager = StringIdManager::instance();

	int xpAmount = templateData->getXpAmount();

	if (xpAmount > 0) {
		String xpTypeNeeded = "@exp_n:" + templateData->getXpType();
		UnicodeString xpType = String::valueOf(xpAmount) + " " + stringIdManager->getStringId(xpTypeNeeded.hashCode());
		alm->insertAttribute("experience_required", xpType);
	}

	String skillNeeded = templateData->getRequiredSkill();

	if (skillNeeded != "") {
		skillNeeded = "@skl_n:" + skillNeeded;
		UnicodeString skill = stringIdManager->getStringId(skillNeeded.hashCode());
		alm->insertAttribute("skill_required", skillNeeded);
	}
}