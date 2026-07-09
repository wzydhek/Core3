#include "CommandList.h"

CommandList::CommandList() : commands(700) {
	setLoggingName("CommandList");

	setGlobalLogging(true);
	setLogging(false);
}

void CommandList::put(QueueCommand* value) {
	uint32 crc = value->getNameCRC();

	debug() << "adding queueCommand 0x" << hex << crc << " " << value->getQueueCommandName();

	commands.put(crc, value);
}

void CommandList::put(const String& name, QueueCommand* value) {
	uint32 crc = name.hashCode();

	debug() << "adding queueCommand 0x" << hex << crc << " " << name;

	commands.put(crc, value);
}

QueueCommand* CommandList::getSlashCommand(const String& aname) {
	uint32 crc = aname.hashCode();

	return commands.get(crc);
}

QueueCommand* CommandList::getSlashCommand(uint32 crc) {
	return commands.get(crc);
}

const QueueCommand* CommandList::getSlashCommand(const String& aname) const {
	uint32 crc = aname.hashCode();

	return commands.get(crc);
}

const QueueCommand* CommandList::getSlashCommand(uint32 crc) const {
	return commands.get(crc);
}

HashTableIterator<uint32, Reference<QueueCommand*>> CommandList::iterator() const {
	return commands.iterator();
}

int CommandList::size() const {
	return commands.size();
}