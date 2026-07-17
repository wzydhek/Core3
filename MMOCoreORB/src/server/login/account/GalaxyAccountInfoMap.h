/*
 * GalaxyAccountInfoMap.h
 *
 *  Created on: 4/30/2016
 *      Author: gslomin
 */

#pragma once

#include "server/login/account/GalaxyAccountInfo.h"

namespace server {
namespace login {
namespace account {

class GalaxyAccountInfoMap : public VectorMap<String, Reference<GalaxyAccountInfo*> > {
public:
	GalaxyAccountInfoMap();
	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);


	friend void to_json(nlohmann::json& j, const GalaxyAccountInfoMap& p);
};

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;
