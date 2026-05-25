/*
 * GalaxyAccountInfoMap.h
 *
 *  Created on: 4/30/2016
 *      Author: gslomin
 */

#pragma once

#include "server/login/account/GalaxyAccountInfo.h"

class GalaxyAccountInfoMap : public VectorMap<String, Reference<GalaxyAccountInfo*> > {
public:
	GalaxyAccountInfoMap();
	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);


	friend void to_json(nlohmann::json& j, const GalaxyAccountInfoMap& p);
};
