/*
 * SharedCellObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"

class SharedCellObjectTemplate : public SharedObjectTemplate {
protected:

public:
	SharedCellObjectTemplate();

	~SharedCellObjectTemplate();

	void readObject(IffStream* iffStream);
};
