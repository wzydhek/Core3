#pragma once

#include "templates/tangible/ContainerTemplate.h"

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
