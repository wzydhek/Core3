 /*
 * SharedTangibleObjectTemplate.h
 *
 *  Created on: 30/04/2010
 *      Author: victor
 */

#pragma once

#include "templates/crafting/resourceweight/ResourceWeight.h"
#include "templates/SharedObjectTemplate.h"

class StructureFootprint;

class SharedTangibleObjectTemplate : public SharedObjectTemplate {
protected:
	/*PaletteColorCustomizationVariables paletteColorCustomizationVariables;
	RangedIntCustomizationVariables rangedIntCustomizationVariables;

	SocketDestinations socketDestinations;*/

	Reference<const StructureFootprint*> structureFootprint;

	BoolParam targetable;

	uint16 playerUseMask;

	int level;

	Vector<String> certificationsRequired;

	int maxCondition;

	uint32 optionsBitmask;
	uint32 pvpStatusBitmask;

	int useCount;

	bool sliceable;

	bool insurable;
	bool jediRobe;

	bool invisible;

	unsigned int faction;

	int junkDealerNeeded;
	int junkValue;

	VectorMap<String, int> skillMods;

	Vector<short>* numberExperimentalProperties;
	Vector<String>* experimentalProperties;
	Vector<short>* experimentalWeights;
	Vector<String>* experimentalAttributes;
	Vector<String>* experimentalGroups;
	Vector<float>* experimentalMin;
	Vector<float>* experimentalMax;
	Vector<short>* experimentalPrecision;
	Vector<short>* experimentalCombineType;
	Vector<uint32>* playerRaces;

	Vector<Reference<ResourceWeight* > >* resourceWeights;
	//CustomizationVariableMapping customizationVariableMapping;

public:
	SharedTangibleObjectTemplate();

	~SharedTangibleObjectTemplate();

	void readObject(LuaObject* templateData) override;
	void readObject(IffStream* iffStream) override;

	void parseFileData(IffStream* str);

	void parseVariableData(const String& varName, Chunk* data);
	void parseVariableData(const String& varName, LuaObject* data);

	int getMaxCondition() const;

	uint32 getOptionsBitmask() const;

	uint32 getPvpStatusBitmask() const;

	void setMaxCondition(int maxCondition);

	void setOptionsBitmask(uint32 optionsBitmask);

	void setPvpStatusBitmask(uint32 pvpStatusBitmask);

	const Vector<String>& getCertificationsRequired() const;

	int getLevel() const;

	bool isInvisible() const;

	int getUseCount() const;

	uint16 getPlayerUseMask() const;

	unsigned int getFaction() const;

	int getJunkDealerNeeded() const;

	int getJunkValue() const;

	const StructureFootprint* getStructureFootprint() const;

	bool getTargetable() const;

	void setCertificationsRequired(Vector<String> certificationsRequired);

	void setPlayerUseMask(uint16 playerUseMask);

	void setTargetable(bool targetable);

	bool getSliceable() const;

	bool isInsurable() const;

	void setInsurable(bool val);

	bool isJediRobe() const;

	void setJediRobe(bool val);

	const Vector<short>* getNumberExperimentalProperties() const;

	const Vector<String>* getExperimentalProperties() const;

	const Vector<short>* getExperimentalWeights() const;

	const Vector<String>* getExperimentalGroups() const;

	const Vector<String>* getExperimentalAttributes() const;

	const Vector<float>* getExperimentalMin() const;

	const Vector<float>* getExperimentalMax() const;

	const Vector<short>* getExperimentalPrecision() const;

	const Vector<uint32>* getPlayerRaces() const;

	const Vector<Reference<ResourceWeight*>>* getResourceWeights() const;

	const VectorMap<String, int>* getSkillMods() const;

	int getSkillMod(const String& mod) const;

	bool isSharedTangibleObjectTemplate() const override;
};
