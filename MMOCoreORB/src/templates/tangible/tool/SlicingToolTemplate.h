/*
 * SlicingToolTemplate.h
 *
 *  Created on: Mar 6, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {
namespace tool {

class SlicingToolTemplate : public SharedTangibleObjectTemplate {
private:
	float effectiveness;

public:
	SlicingToolTemplate();

	~SlicingToolTemplate();

	void readObject(LuaObject* templateData) override;

	float getEffectiveness() const;

};

} // namespace tool
} // namespace tangible
} // namespace templates

using namespace templates::tangible::tool;
