/*
 * SharedGuildObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedUniverseObjectTemplate.h"

namespace templates {
namespace universe {

class SharedGuildObjectTemplate : public SharedUniverseObjectTemplate {
public:
	SharedGuildObjectTemplate();

	~SharedGuildObjectTemplate();

	void readObject(IffStream* iffStream);
};

} // namespace universe
} // namespace templates

using namespace templates::universe;