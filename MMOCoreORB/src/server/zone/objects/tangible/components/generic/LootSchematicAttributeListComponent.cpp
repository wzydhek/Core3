#include "LootSchematicAttributeListComponent.h"

void LootSchematicAttributeListComponent::fillAttributeList(AttributeListMessage* alm, CreatureObject* creature, SceneObject* object) const {
	LootSchematicTemplate* schematicData = cast<LootSchematicTemplate*>(object->getObjectTemplate());
	if (schematicData == nullptr) {
		return;
	}

	String skillNeeded = "@skl_n:" + schematicData->getRequiredSkill();
	StringIdManager* stringIdManager = StringIdManager::instance();

	UnicodeString skill = stringIdManager->getStringId(skillNeeded.hashCode());

	if (!skill.isEmpty())
		alm->insertAttribute("skill_required", skill);
}