#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class XpPurchaseTemplate : public SharedTangibleObjectTemplate {
protected:
	String requiredSkill;
	String xpType;
	String grantType, grantName;
	int xpAmount;
	bool noRemove;

public:
	XpPurchaseTemplate();

	~XpPurchaseTemplate();

	void readObject(LuaObject* templateData);

	const String& getRequiredSkill();

	const String& getGrantType();

	const String& getGrantName();

	const String& getXpType();

	bool isNoRemove();

	int getXpAmount();
};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
