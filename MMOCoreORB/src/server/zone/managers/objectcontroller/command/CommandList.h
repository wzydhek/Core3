/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {
namespace command {

class CommandList : public Logger, public Object {
	HashTable<uint32, Reference<QueueCommand*> > commands;

public:
	CommandList();

	void put(QueueCommand* value);

	void put(const String& name, QueueCommand* value);

	QueueCommand* getSlashCommand(const String& aname);

	QueueCommand* getSlashCommand(uint32 crc);

	const QueueCommand* getSlashCommand(const String& aname) const;

	const QueueCommand* getSlashCommand(uint32 crc) const;

	HashTableIterator<uint32, Reference<QueueCommand*>> iterator() const;

	int size() const;
};


}
}
}
}
}

using namespace server::zone::managers::objectcontroller::command;
