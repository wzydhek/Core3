/*
 * InteriorLayoutTemplate.h
 *
 *  Created on: 4/20/2016
 *      Author: GSlomin
 */

#pragma once

#include "../IffTemplate.h"

class InteriorNode : public Object {
	Matrix4 transform;
	String templateFile;
	String cellName;
public:
	InteriorNode();

	void load(IffStream* iff);

	const Matrix4& getTransform();

	const String& getTemplateFile();

	const String& getCellName();
};

class InteriorLayoutTemplate : public IffTemplate {
	String name;
	Vector<Reference<InteriorNode*> > children;
public:
	InteriorLayoutTemplate();

	void readObject(IffStream* iff);

	const Vector<Reference<InteriorNode*>>& getChildren() const;
};
