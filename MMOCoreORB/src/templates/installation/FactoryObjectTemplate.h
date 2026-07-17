/*
 * SharedFactoryObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/installation/SharedInstallationObjectTemplate.h"

namespace templates {
namespace installation {

class FactoryObjectTemplate : public SharedInstallationObjectTemplate {
public:
	Vector<int> craftingTabsSupported;

public:
	FactoryObjectTemplate();

	~FactoryObjectTemplate();

	void readObject(LuaObject* templateData);

	Vector<int> getCraftingTabsSupported();

	bool isFactoryObjectTemplate();
};

} // namespace installation
} // namespace templates

using namespace templates::installation;
