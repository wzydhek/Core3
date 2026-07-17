#pragma once

#include "templates/tangible/ContainerTemplate.h"

namespace templates {
namespace tangible {
namespace tool {

class RecycleToolTemplate : public ContainerTemplate {
private:

	short toolType;
	Vector<String> resourceTypes;

public:
	RecycleToolTemplate();

	~RecycleToolTemplate();

	void readObject(LuaObject* templateData) override;

	short getToolType() const;

	const Vector<String>& getResourceTypes() const;

	bool isRecycleToolTemplate() const override;
};

} // namespace tool
} // namespace tangible
} // namespace templates

using namespace templates::tangible::tool;
