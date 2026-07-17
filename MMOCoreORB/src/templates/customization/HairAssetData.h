/*
 * HairAssetData.h
 *
 *  Created on: 29/03/2012
 *      Author: victor
 */

#pragma once

#include "system/lang.h"
#include "templates/datatables/DataTableRow.h"

namespace templates {
namespace customization {

class HairAssetData : public Object {
	String sharedTemplate;
	String playerTemplate;
	int skillModValue;
	bool availableAtCreation;
	String serverTemplate;
	String serverPlayerTemplate;

public:
	HairAssetData();

	void readObject(DataTableRow* row);

	bool isAvailableAtCreation() const;

	String getPlayerTemplate() const;

	String getServerPlayerTemplate() const;

	void setServerPlayerTemplate(const String& serverPlayerTemplate);

	String getServerTemplate() const;

	String getSharedTemplate() const;

	int getSkillModValue() const;
};

} // namespace customization
} // namespace templates

using namespace templates::customization;
