/*
 * TemplateCRCMap.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"
#include "templates/TemplateReference.h"

namespace templates {

class TemplateCRCMap : public HashTable<uint32, TemplateReference<SharedObjectTemplate*> > {
	int hash(const uint32& k) const override;

public:
	TemplateCRCMap();
};

class ClientTemplateCRCMap : public HashTable<uint32, String> {
	int hash(const uint32& k) const override;

public:
	ClientTemplateCRCMap();
};

} // namespace templates

using namespace templates;
