/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneProcessServer.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class QueueCommand : public Logger, public Object {
protected:
	ZoneProcessServer* server;

	String name;
	uint32 nameCRC;

	uint64 stateMask;
	Vector<int> invalidLocomotion;
	//int target;
	int targetType;
	int maxRangeToTarget;

	bool disabled;
	bool addToQueue;
	bool admin;

	uint32 cooldown; // in msec
	String cooldownString;
	String cooldownName;

	float defaultTime;

	String characterAbility;

	int defaultPriority;

	VectorMap<String, int> skillMods;

	int commandGroup;

public:
	QueueCommand(const String& skillname, ZoneProcessServer* serv);

	const static int NOCOMBATQUEUE = -1;
	const static int IMMEDIATE = 0;
	const static int FRONT = 1;
	const static int NORMAL = 2;

	const static int SUCCESS = 0;
	const static int GENERALERROR = 1;
	const static int INVALIDLOCOMOTION = 2;
	const static int INVALIDSTATE = 3;
	const static int INVALIDTARGET = 4;
	const static int INVALIDWEAPON = 5;
	const static int TOOFAR = 6;
	const static int INSUFFICIENTHAM = 7;
	const static int INVALIDPARAMETERS = 8;
	const static int NOPRONE = 9;
	const static int NOKNEELING = 10;
	const static int INSUFFICIENTPERMISSION = 11;
	const static int NOJEDIARMOR = 12;
	const static int INVALIDSYNTAX = 13;
	const static int TOOCLOSE = 14;
	const static int NOSTACKJEDIBUFF = 15;
	const static int ALREADYAFFECTEDJEDIPOWER = 16;

	virtual ~QueueCommand() {
	}

	/*
	 * Checks each invalid locomotion with the player's current locomotion
	 */
	bool checkInvalidLocomotions(CreatureObject* creature) const;

	/*
	*	Checks cell access for the player creature if the target is in a cell
	*/
	bool playerEntryCheck(CreatureObject* creature, TangibleObject* target) const;

	void onStateFail(CreatureObject* creature, uint32 actioncntr) const;
	void onLocomotionFail(CreatureObject* creature, uint32 actioncntr) const;

	bool checkForArenaDuel(CreatureObject* target) const;

	/**
	 * Gets a string describing this commands syntax usage.
	 */
	virtual String getSyntax() const;

	/*
	 * Unsuccessful command completion alerts the player of the invalid state, must clear the queue action from client queue
	 */
	virtual void onFail(uint32 actioncntr, CreatureObject* creature, uint32 errorNumber) const;

	/*
	 * Successful command completion, must clear the queue action from client queue
	 */
	virtual void onComplete(uint32 actioncntr, CreatureObject* creature, float commandDuration) const;

	/*
	 * Sets the invalid locomotions for this command.
	 * Parses the string from LUA's. Format: "4,12,13,"
	 */
	void setInvalidLocomotions(const String& lStr);

	/*
	 * adds an invalid locomotion
	 */
	void addInvalidLocomotion(int l);

	bool checkDistance(SceneObject* source, SceneObject* target, float range) const;

	/*
	 * Override me
	 */
	virtual int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const = 0;

	/*
	 * Checks all states at once with a bitwise operation
	 */
	bool checkStateMask(CreatureObject* creature) const;

	bool checkSpaceStates(CreatureObject* creature) const;

	/**
	 * Returns duration of the command
	 */

	virtual float getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const;

	//setters

	/*
	 * Sets the invalid states for this command
	 */
	void setStateMask(uint64 mask);

	/*inline void setTarget(int num) {
		target = num;
	}*/

	void setDefaultTime(float time);

	void setTargetType(int num);

	void setDisabled(bool state);

	void setDisabled(int state);

	void setAddToCombatQueue(bool state);

	void setAddToCombatQueue(int state);

	void setCommandGroup(int val);

	void setMaxRange(float r);

	void setCharacterAbility(const String& ability);

	void setDefaultPriority(const String& priority);

	void setDefaultPriority(const int priority);

	//getters
	uint64 getStateMask() const;

	bool requiresAdmin() const;

	int getTargetType() const;

	String getName() const;

	uint32 getNameCRC() const;

	virtual float getMaxRange() const;

	const String& getQueueCommandName() const;

	const String& getCharacterAbility() const;

	float getDefaultTime() const;

	int getDefaultPriority() const;

	/*
	 * @return True if the command has been disabled by the admins
	 */
	bool isDisabled() const;

	/*
	 * @return True if the command is supposed to be added to the combat queue.
	 */
	bool addToCombatQueue() const;

	virtual bool isCombatCommand() const;

	virtual bool isForceHealCommand() const;

	virtual bool isJediQueueCommand() const;

	virtual bool isJediCombatCommand() const;

	bool isJediCommand() const;

	int getSkillModSize() const;

	int getSkillMod(int index, String& skillMod) const;

	int getCommandGroup() const;

	void addSkillMod(const String& skillMod, const int value);

	bool isWearingArmor(CreatureObject* creo) const;

	void setCooldownString(String msg);

	String getCooldownString() const;

	void setCooldownName(String name);

	String getCooldownName() const;

	void setCooldown(int cooldownMili);

	inline int getCooldown() const;

	bool checkCooldown(CreatureObject* creo) const;

	virtual void handleBuff(SceneObject* creature, ManagedObject* object, int64 param) const;

	int doCommonMedicalCommandChecks(CreatureObject* creature) const;

	void checkForTef(CreatureObject* creature, CreatureObject* target) const;

	String toStringData() const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
