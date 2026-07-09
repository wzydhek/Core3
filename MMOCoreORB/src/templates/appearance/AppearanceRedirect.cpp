#include "AppearanceRedirect.h"

AppearanceRedirect::AppearanceRedirect() {
}

void AppearanceRedirect::readObject(IffStream* iffStream) {
	iffStream->openForm('APT ');
	iffStream->openForm('0000');

	iffStream->openChunk('NAME');

	iffStream->getString(redirectFile);

	iffStream->closeChunk();

	iffStream->closeForm('0000');
	iffStream->closeForm('APT ');
}

String AppearanceRedirect::getRedirectFile() {
	return redirectFile;
}