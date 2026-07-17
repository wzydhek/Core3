/*
 * AppearanceRedirect.h
 *
 *  Created on: 16/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace appearance {

class AppearanceRedirect : public IffTemplate {
	String redirectFile;
public:
	AppearanceRedirect();

	void readObject(IffStream* iffStream);

	String getRedirectFile();
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
