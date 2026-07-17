/*
 * CustomizationVariable.h
 *
 *  Created on: 01/04/2011
 *      Author: victor
 */

#pragma once

#include "system/lang.h"

namespace templates {
namespace customization {

class CustomizationVariable : public Object {
public:
	CustomizationVariable() {

	}

	CustomizationVariable(const CustomizationVariable& o) : Object() {

	}
};

} // namespace customization
} // namespace templates

using namespace templates::customization;
