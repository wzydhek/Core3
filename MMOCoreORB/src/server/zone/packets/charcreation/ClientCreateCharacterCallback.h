/*
 * ClientCreateCharacterCallback.h
 *
 *  Created on: Sep 5, 2009
 *      Author: theanswer
 */

#pragma once

#include "server/zone/packets/MessageCallback.h"

class ClientCreateCharacterCallback : public MessageCallback {
	String customization;

	UnicodeString characterName;

	String racefile;
	String location;
	String hairobj;
	String haircust;
	String profession;

	int species;

	float height;
	UnicodeString bio;
	uint8 tutflag;

public:
	ClientCreateCharacterCallback(ZoneClientSession* client, ZoneProcessServer* server);

	void parse(Message* message);

	void run();

	void getRaceFile(String& file) const;

	void getCustomizationString(String& customizationString) const;

	void getLocation(String& location) const;

	void getHairObject(String& hair) const;

	void getHairCustomization(String& hairCustomization) const;

	void getSkill(String& profession) const;

	float getHeight() const;

	void getBiography(UnicodeString& biography) const;

	bool getTutorialFlag() const;

	void getCharacterName(UnicodeString& name) const;

	int getSpecies() const;
};
