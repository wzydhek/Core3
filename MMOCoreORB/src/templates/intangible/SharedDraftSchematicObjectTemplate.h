/*
 * SharedDraftSchematicObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

namespace templates {
namespace intangible {

class SharedDraftSchematicObjectTemplate : public SharedIntangibleObjectTemplate {
public:
	SharedDraftSchematicObjectTemplate();

	~SharedDraftSchematicObjectTemplate();

	void readObject(IffStream* iffStream);

	void readObject(LuaObject* templateData);
};

} // namespace intangible
} // namespace templates

using namespace templates::intangible;
