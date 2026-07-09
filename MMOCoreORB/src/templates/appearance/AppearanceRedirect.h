/*
 * AppearanceRedirect.h
 *
 *  Created on: 16/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/IffTemplate.h"

class AppearanceRedirect : public IffTemplate {
	String redirectFile;
public:
	AppearanceRedirect();

	void readObject(IffStream* iffStream);

	String getRedirectFile();
};
