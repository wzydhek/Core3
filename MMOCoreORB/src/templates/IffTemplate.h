/*
 * IffTemplate.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "engine/util/iffstream/IffStream.h"
#include "templates/TemplateData.h"

namespace templates {

class IffTemplate : public virtual TemplateData {
public:
	virtual void readObject(IffStream* templateData) = 0;

	virtual ~IffTemplate() {

	}
};

} // namespace templates

using namespace templates;