/*
 * SharedMissionDataObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

namespace templates {
namespace intangible {

class SharedMissionDataObjectTemplate : public SharedIntangibleObjectTemplate {
public:
	SharedMissionDataObjectTemplate();

	~SharedMissionDataObjectTemplate();

	void readObject(IffStream* iffStream);
};

} // namespace intangible
} // namespace templates

using namespace templates::intangible;
