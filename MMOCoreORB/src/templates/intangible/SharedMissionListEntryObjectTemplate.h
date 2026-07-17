/*
 * SharedMissionListEntryObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

namespace templates {
namespace intangible {

class SharedMissionListEntryObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedMissionListEntryObjectTemplate();

	~SharedMissionListEntryObjectTemplate();

	void readObject(IffStream* iffStream);

};

} // namespace intangible
} // namespace templates

using namespace templates::intangible;
