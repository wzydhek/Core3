/*
 * SharedDraftSchematicObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "SharedDraftSchematicObjectTemplate.h"
#include "templates/SharedTangibleObjectTemplate.h"
#include "templates/crafting/draftslot/DraftSlot.h"

namespace templates {
namespace intangible {

class DraftSchematicObjectTemplate : public SharedDraftSchematicObjectTemplate {
protected:

	String customObjectName;

	int craftingToolTab;
	// The number that tells the client which crafting tool tab to put the draftSchematic in
	/*
	 * BITMASK FOR TABS
	 * 0 = unknown													0000
	 * 1 = weapons													0001
	 * 2 = armor													0010
	 * 4 = food														0100
	 * 8 = clothing													1000
	 * 16 = vehicle											   0001 0000
	 * 32 =	droid											   0010 0000
	 * 64 = chemical										   0100 0000
	 * 128 = tissues									  	   1000 0000
	 * 256 = creatures									  0001 0000 0000
	 * 512 = furniture									  0010 0000 0000
	 * 1024 = installation								  0100 0000 0000
	 * 2048 = lightsaber							 	  1000 0000 0000
	 * 4096 = generic item							 0001 0000 0000 0000
	 * 8192 = genetics								 0010 0000 0000 0000
	 * 16384 = Tailor, Mandalorian					 0100 0000 0000 0000
	 * 32768 = armorsmith, Mandalorian				 1000 0000 0000 0000
	 * 65536 = Droid Engineer, Mandalorian		0001 0000 0000 0000 0000
	 * 131072 = Starship Components				0010 0000 0000 0000 0000
	 * 262144 = Ship Tools						0100 0000 0000 0000 0000
	 * 524288 = Misc							1000 0000 0000 0000 0000
	 * 2148007936 = Mission      1000 0000 0000 1000 0000 0000 0000 0000
	 * * */

	short complexity;
	short size;

	String xpType;
	int xp;

	bool isMagic;
	String assemblySkill;
	String experimentingSkill;
	String customizationSkill;

	Vector<String>* ingredientTemplateNames;
	Vector<String>* ingredientTitleNames;
	Vector<short>* ingredientSlotType;
	Vector<String>* ingredientAppearance;
	Vector<String>* resourceTypes;
	Vector<int>* resourceQuantities;
	Vector<short>* contribution;

	Vector<String>* additionalTemplates;

	Vector<Reference<DraftSlot* > >* draftSlots;

	SharedTangibleObjectTemplate* tangibleTemplate;

	uint32 tanoCRC;

	VectorMap<String, int> skillMods;

	Vector<VectorMap<String, int> > weaponDots;

	int labratory;

	int factoryCrateSize;

	String factoryCrateType;

public:
	enum LabType {
		RESOURCE_LAB = 0x00,
		GENETIC_LAB = 0x01,
		DROID_LAB = 0x02
	};

	DraftSchematicObjectTemplate();

	~DraftSchematicObjectTemplate();

	void readObject(LuaObject* templateData);

	void parseVariableData(const String& varName, LuaObject* data);

	const Vector<Reference<DraftSlot*>>* getDraftSlots() const;

	void addSlot(DraftSlot* slot);

	bool getIsMagic() const;

	const String& getAssemblySkill() const;

	short getComplexity() const;

	const Vector<short>* getContribution() const;

	int getCraftingToolTab() const;

	const String& getExperimentingSkill() const;

	const String& getCustomizationSkill() const;

	const Vector<short>* getIngredientSlotType() const;

	const Vector<String>* getIngredientAppearance() const;

	const String& getIngredientAppearance(int i) const;

	const Vector<String>* getIngredientTemplateNames() const;

	const Vector<String>* getIngredientTitleNames() const;

	const Vector<int>* getResourceQuantities() const;

	const Vector<String>* getResourceTypes() const;

	short getSize() const;

	uint32 getTanoCRC() const;

	int getXp() const;

	const String& getXpType() const;

	const String& getCustomObjectName() const;

	int getTemplateListSize() const;

	const String& getTemplate(int i) const;

	const Vector<Reference<ResourceWeight* > >* getResourceWeights();

	const VectorMap<String, int>* getSkillMods() const;

	int getSkillMod(const String& mod) const;

	const Vector<VectorMap<String, int>>* getWeaponDots() const;

	int getLabratory() const;

	int getFactoryCrateSize() const;

	const String& getFactoryCrateType() const;

};

} // namespace intangible
} // namespace templates

using namespace templates::intangible;
