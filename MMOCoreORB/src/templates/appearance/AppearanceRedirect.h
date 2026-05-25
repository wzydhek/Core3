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
	AppearanceRedirect() {

	}

	void readObject(IffStream* iffStream) {
		iffStream->openForm('APT ');
		iffStream->openForm('0000');

		iffStream->openChunk('NAME');

		iffStream->getString(redirectFile);

		iffStream->closeChunk();

		iffStream->closeForm('0000');
		iffStream->closeForm('APT ');
	}

	inline String getRedirectFile() {
		return redirectFile;
	}
};
