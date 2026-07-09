#pragma once

#include "server/zone/managers/creature/DnaManager.h"
#include "server/zone/objects/tangible/component/dna/DnaComponent.h"
#include "server/zone/objects/tangible/component/genetic/GeneticComponent.h"
#include "templates/params/creature/ObjectFlag.h"

namespace server {
namespace zone {
namespace managers {
namespace crafting {
namespace labratories {

// #define DEBUG_GENETIC_LAB

class Genetics {
private:
	const static short PHYSIQUE = 0;
	const static short PROWESS = 1;
	const static short MENTAL = 2;
	const static short AGRESSION = 3;
	const static short PHYSCHOLOGICAL = 4;
public:
	const static constexpr float ACID_MAX = 100.0f;
	const static constexpr float BLAST_MAX = 100.0f;
	const static constexpr float COLD_MAX = 100.0f;
	const static constexpr float ELECTRICITY_MAX = 100.0f;
	const static constexpr float ENERGY_MAX = 60.0f;
	const static constexpr float HEAT_MAX = 100.0f;
	const static constexpr float KINETIC_MAX = 60.0f;
	const static constexpr float STUN_MAX = 100.0f;
	//const static constexpr float LIGHTSABER_MAX = 100.f;

	// Hardiness and Fortiture
	static float physiqueFormula(float physique, float prowess, float mental, float psychology, float aggression);

	// Dexterity and Endurance
	static float prowessFormula(float physique, float prowess, float mental, float psychology, float aggression);

	// Intellect and Cleverness
	static float mentalFormula(float physique, float prowess, float mental, float psychology, float aggression);

	// Dependability and Courage
	static float physchologicalFormula(float physique, float prowess, float mental, float psychology, float aggression);

	// Fierceness and Power
	static float aggressionFormula(float physique, float prowess, float mental, float psychology, float aggression);

	/**
	 * Any special in the line
	 */
	static bool hasSpecialResist(DnaComponent* componentA, DnaComponent* componentB, DnaComponent* componentC, DnaComponent* componentD, DnaComponent* componentE, int type);

	/**
	 * Any vulnerability int he line
	 */
	static bool hasVulnerability(float a, float b, float c, float d, float e);

	/*
		Get proper resistance for calculation
	*/
	static float getProperResistance(float value, bool special, bool override);

	/**
	 * Resistnce calculation formula
	 */
	static float resistanceFormula(DnaComponent* componentA, DnaComponent* componentB, DnaComponent* componentC, DnaComponent* componentD, DnaComponent* componentE, int type, int max);

	static float initialValue(float maxValue);

	/**
	 * New Genetics Code - washu 03/08/15
	 */
	// convert creature hit chance to cleverness value
	static int hitChanceToValue(float input, int quality);

	// convert creature damage range to power score
	static int damageToValue(float dps, int quality);

	// convert ham value to score
	static int hamToValue(float ham, int quality);

	// convert ferocity value
	static int ferocityToValue(int level, int quality);

	// convert acceletation
	static int accelerationToValue(float speed, int quality);

	// convert meat type to value
	static int meatTypeToValue(String type, int quality);

	// convert diet to value
	static int dietToValue(int diet, int quality);

	// convert resistance to value
	static float resistanceToValue(float effective, int armor, int quality);

	static int randomizeValue(int value, int quality);

	// Calculate the creatures overall level as a pet.
	static int calculatePetLevel(GeneticComponent* pet);

	static int calculateAgentLevel(int health, float dps, float hit, int regen, int armor, float effective, float kin, float eng, float bla, float heat, float cold, float elec, float acid, float stun);

	// calculate the armor level for a pet
	static int calculateArmorValue(GeneticComponent* pet, int armorLevel, int baseLevel, int armorBase);

	// calculate the resistance level modifier
	static int resistMath(int input, int rating, int effectiveness, bool multiply, int multValue, int lowValue);

	static float determineMaxExperimentation(float min, float max);

	// level factor rules
	static float calculateArmorLevel(float armorBase);

	// dps to level range
	static float calculateDPSLevel(float maxDamage, float minDamage);

	// ham level
	static float calculateHamLevel(float ham);

	// regen level
	static float calculatRegenLevel(float regen);

	// hit level
	static float calculatHitLevel(float toHit);

	static int calcArmorLevelByStats(int armorRating, int armorLevel, int baseLevel, int armorBase, float kinetic, float energy, float blast, float heat, float cold, float electricity, float acid, float stun);

	static float generateStatLevel(int health);

	static float generateDamageLevel(float dps);

	static float generateHitLevel(float hitChance);

	static float generateRegenLevel(int hamRegen);

	static float generteArmorLevel(int armor, float effectResist);

	static float generateArmorBaseLevel(int generatedArmorLevel);

	static float generateBaseLevel(int statLevel, int damageLevel, int armorLevel, int regenLevel, int hitLevel);

	// Calculate the input creature levels
	static int levelForCreature(Creature* creature);

};

} // namespace labratories
} // namespace crafting
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::crafting::labratories;
