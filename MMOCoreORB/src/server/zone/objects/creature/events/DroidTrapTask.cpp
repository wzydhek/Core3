#include "DroidTrapTask.h"

DroidTrapTask::DroidTrapTask(CreatureObject* p, CreatureObject* t, CreatureObject* dr, Buff* b, const StringIdChatParameter& m, short po, int d, bool h) : Task(2300) {
	player = p;
	target = t;
	droid = dr;
	buff = b;
	message = m;
	damage = d;
	pool = po;
	hit = h;
}

DroidTrapTask::~DroidTrapTask() {
}

void DroidTrapTask::run() {
	if (player == nullptr || target == nullptr || droid == nullptr)
		return;

	Locker locker2(droid);
	droid->removePendingTask("throwtrap");
	droid->sendSystemMessage(message);

	if (hit) {
		Locker locker(target, droid);

		if (buff != nullptr) {
			Locker locker(buff);
			target->addBuff(buff);
		}

		target->inflictDamage(droid, pool, damage, true);

		// Players get the full trap xp, as per http://www.swgemu.com/archive/scrapbookv51/data/20070127195942/
		//  Players get 1/2 rating according to http://wiki.swganh.org/index.php/Scout_Trap_Projectile_Unit_Module_Usage_%28Game_Mechanics%29
		//  i learn towards the offical forum posts
		int xp = target->getLevel() * 15;
		ManagedReference<PlayerManager*> playerManager = player->getZoneServer()->getPlayerManager();
		if (playerManager != nullptr) {
			locker.release(); // release the target
			Locker clock(player, droid);
			playerManager->awardExperience(player, "trapping", xp, true);
		}
	}
}