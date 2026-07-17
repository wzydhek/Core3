/*
 * TemplateData.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "system/lang/Object.h"

namespace templates {

class TemplateData : public virtual Object {
public:
	constexpr const static bool is_virtual_object = true;

	virtual ~TemplateData() {

	}
};

} // namespace templates

using namespace templates;