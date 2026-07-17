/*
 * SharedJediManagerTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedUniverseObjectTemplate.h"

namespace templates {
namespace universe {

class SharedJediManagerTemplate : public SharedUniverseObjectTemplate {
public:
	SharedJediManagerTemplate();

	~SharedJediManagerTemplate();

	void readObject(IffStream* iffStream);
};

} // namespace universe
} // namespace templates

using namespace templates::universe;