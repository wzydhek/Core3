#include "AnimationTask.h"

AnimationTask::AnimationTask(CreatureObject* creo, const String& anim) {
	creature = creo;
	animation = anim;
}

void AnimationTask::run() {
	Locker locker(creature);

	creature->doAnimation(animation);
}