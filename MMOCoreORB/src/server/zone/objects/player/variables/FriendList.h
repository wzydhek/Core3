/*
 * FriendList.h
 *
 *  Created on: 05/02/2010
 *      Author: victor
 */

#pragma once

#include "PlayerList.h"

class FriendList : public PlayerList<7> {
protected:
	Vector<String> reverseTable;

public:
	FriendList();

	FriendList(const FriendList& list);

	FriendList& operator=(const FriendList& list);

	bool readObjectMember(ObjectInputStream* stream, const String& name);

	int writeObjectMembers(ObjectOutputStream* stream);

	bool toBinaryStream(ObjectOutputStream* stream);

	friend void to_json(nlohmann::json& j, const FriendList& l);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	void addReversePlayer(const String& name);

	void removeReversePlayer(const String& name);

	String getReversePlayer(int idx);

	int reversePlayerCount();

};
