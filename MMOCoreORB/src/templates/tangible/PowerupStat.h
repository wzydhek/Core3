/*
 * PowerupStat.h
 *
 *  Created on: Mar 06, 2012
 *      Author: kyle
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace templates {
namespace tangible {

class PowerupStat: public virtual Serializable {
protected:
	SerializableString attributeToModify;
	SerializableString name;
	SerializableString pupAttribute;
	float value;
public:

	PowerupStat();

	PowerupStat(const PowerupStat& p);

	PowerupStat(const String& att, const String& n, const String& p);

	PowerupStat& operator=(const PowerupStat& p);

	bool operator==(const PowerupStat& stat);

	friend void to_json(nlohmann::json& j, const PowerupStat& s) {
		j["attributeToModify"] = s.attributeToModify;
		j["name"] = s.name;
		j["pupAttribute"] = s.pupAttribute;
		j["value"] = s.value;
	}

	void addSerializableVariables();

	const String& getAttributeToModify() const;

	const String& getName() const;

	const String& getPupAttribute() const;

	float getValue() const;

	void setValue(float v);
};


} // namespace tangible
} // namespace templates

using namespace templates::tangible;
