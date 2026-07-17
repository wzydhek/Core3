#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace skill {
class SkillManager;
}
}
}
}

using namespace server::zone::managers::skill;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

class Skill : public Object {
protected:
	WeakReference<Skill*> parentNode;
	Vector<Reference<Skill*> > childNodes;

	String skillName;
	String parentName;
	int graphType;

	bool godOnly;
	bool title;
	bool profession;
	bool hidden;
	bool searchable;

	int moneyRequired;
	int pointsRequired;
	int skillsRequiredCount;

	Vector<String> skillsRequired;
	Vector<String> preclusionSkills;

	String xpType;

	int xpCost;
	int xpCap;

	Vector<String> missionsRequired;

	int apprenticeshipsRequired;

	Vector<String> statsRequired;
	Vector<String> speciesRequired;

	int jediStateRequired;

	Vector<String> skillAbility;
	Vector<String> commands;
	VectorMap<String, int> skillModifiers;
	Vector<String> schematicsGranted;
	Vector<String> schematicsRevoked;

public:
	Skill();

	~Skill();

	int compareTo(const Skill& s);

	int compareTo(Skill* s);

	void parseDataTableRow(DataTableRow* row);

	void parseLuaObject(LuaObject* templateData);

	const String& getSkillName() const;

	int getJediStateRequired() const;

	bool isGodOnly() const;

	bool isTitle() const;

	bool isSkill() const;

	bool isHidden() const;

	bool isSearchable() const;

	Skill* getParent() const;

	int getTotalChildren() const;

	const Skill* getChildNode(int idx) const;

	bool containsChildNode(Skill* skill) const;

	const String& getParentName() const;

	void addChild(Skill* skill);

	const Vector<String>* getAbilities() const;

	const Vector<String>* getSchematicsGranted() const;

	const VectorMap<String, int>* getSkillModifiers() const;

	const Vector<String>* getSkillsRequired() const;

	bool isRequiredSkillOf(Skill* skill) const;

	const String& getXpType() const;

	int getXpCap() const;

	/**
	 * Returns the XP cost for the skill.
	 * @return XP cost for the skill.
	 */
	int getXpCost() const;

	/**
	 * Returns the credits required for training the skill at a trainer.
	 * @return the credits required for training the skill at a trainer.
	 */
	int getMoneyRequired() const;

	/**
	 * Returns the number of skill points required for the skill.
	 * @return the number of skill points required for the skill.
	 */
	int getSkillPointsRequired() const;

	/**
	 * Returns the species required for the skill.
	 * @return the species required for the skill.
	 */
	const Vector<String>* getSpeciesRequired() const;

private:
	void setParentNode(Skill* skill);

	void parseSkillMods(const String& modstring);

	friend class server::zone::managers::skill::SkillManager;
};

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;
