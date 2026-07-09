/*
 * SharedConstructionContractObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedConstructionContractObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedConstructionContractObjectTemplate();

	~SharedConstructionContractObjectTemplate();

	void readObject(IffStream* iffStream);


};
