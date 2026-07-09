#include "Animation.h"

Animation::Animation(CreatureObject* creo, const String& anim) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0xF2, false) {
	insertAscii(anim.toCharArray());
}