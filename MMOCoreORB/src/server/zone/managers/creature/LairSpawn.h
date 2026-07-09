/*
 * LairSpawn.h
 *
 *  Created on: 11/12/2011
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

	class LairSpawn : public Object {
	protected:
		int spawnLimit;
		int minDifficulty;
		int maxDifficulty;
		int numberToSpawn;
		int weighting;
		float size;

		String lairTemplateName;

	public:
		LairSpawn();

		LairSpawn(const LairSpawn& sp);

		LairSpawn& operator=(const LairSpawn& sp);

		void readObject(LuaObject& obj);

		int getSpawnLimit() const;

		int getMinDifficulty() const;

		int getMaxDifficulty() const;

		int getNumberToSpawn() const;

		int getWeighting() const;

		float getSize() const;

		const String& getLairTemplateName() const;
	};

}
}
}
}

using namespace server::zone::managers::creature;
