/*
 * LootkitObjectTemplate.h
 *
 *  Created on: May 7, 2010
 *      Author: swgemu
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class LootkitObjectTemplate: public SharedTangibleObjectTemplate {
protected:

	VectorMap<uint32, bool> components;
	VectorMap<uint32, String> attributes;
	Vector<uint32> comps;
	Vector<uint32> reward;

	bool deleteComponents;


public:
	LootkitObjectTemplate();

	~LootkitObjectTemplate();

	void readObject(LuaObject* templateData);

	VectorMap<uint32, bool> getComponents() const;

	VectorMap<uint32, String> getAttributes() const;

	Vector<uint32> getComps() const;

	Vector<uint32> getReward() const;

	bool getDeleteComponents() const;

	void setDeleteComponents(bool deleteComponents);

	void setComponents(VectorMap<uint32, bool> components);

	void setAttributes(VectorMap<uint32, String> attributes);

	void setComps(Vector<uint32> comps);

	void setReward(Vector<uint32> reward);

};
