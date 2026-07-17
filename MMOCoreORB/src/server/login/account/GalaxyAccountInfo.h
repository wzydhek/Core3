/*
 * GalaxyAccountInfo.h
 *
 *  Created on: 4/30/2016
 *      Author: gslomin
 */

#pragma once

#include "system/lang.h"
#include "system/util/SynchronizedVectorMap.h"
#include "engine/util/json.hpp"

namespace server {
namespace login {
namespace account {

class GalaxyAccountInfo : public Object {
protected:
	SynchronizedVectorMap<uint32_t, String> chosenVeteranRewards; // milestone, templateFile

public:
	GalaxyAccountInfo();

	void updateVetRewardsFromPlayer(const VectorMap<uint32, String> &newRewards);

	String getChosenVeteranReward(uint32 milestone) const;

	void addChosenVeteranReward(uint32 milestone, const String& rewardTemplate);

	bool hasChosenVeteranReward(const String& rewardTemplate) const;

	void clearVeteranReward(uint32 milestone);

	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);

	friend void to_json(nlohmann::json& j, const GalaxyAccountInfo& p);
};
} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;
