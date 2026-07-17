/*
 * SharedMissionObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

namespace templates {
namespace intangible {

class SharedMissionObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedMissionObjectTemplate();

	~SharedMissionObjectTemplate();

	void readObject(IffStream* iffStream);

};

} // namespace intangible
} // namespace templates

using namespace templates::intangible;
