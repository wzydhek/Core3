/*
 * SharedCellObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"

namespace templates {

class SharedCellObjectTemplate : public SharedObjectTemplate {
protected:

public:
	SharedCellObjectTemplate();

	~SharedCellObjectTemplate();

	void readObject(IffStream* iffStream);
};

} // namespace templates

using namespace templates;