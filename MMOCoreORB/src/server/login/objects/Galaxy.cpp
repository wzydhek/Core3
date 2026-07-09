#include "Galaxy.h"

Galaxy::Galaxy(ResultSet* result) {
	id = result->getUnsignedInt(0);
	name = result->getString(1);
	address = result->getString(2);
	port = result->getUnsignedInt(3);
	pingPort = result->getUnsignedInt(4);
	population = result->getUnsignedInt(5);
#ifdef USE_RANDOM_EXTRA_PORTS
	extraPorts.add(port);

	try {
		String extraPortStrings = result->getString(6);

		if (!extraPortStrings.isEmpty()) {
			StringTokenizer tokenizer(extraPortStrings);
			tokenizer.setDelimiter(",");

			while (tokenizer.hasMoreTokens() && extraPorts.size() < 256) {
				try {
					uint32 newPort = tokenizer.getIntToken();

					if (newPort != 0)
						extraPorts.add(newPort);
				} catch (Exception e) {
					// Do nothing
				}
			}
		}
	} catch (Exception e) {
		// Do Nothing
	}
#endif // USE_RANDOM_EXTRA_PORTS
}

Galaxy::Galaxy(uint32 id) {
	this->id = id;
}

void Galaxy::setID(uint32 id) {
	this->id = id;
}

void Galaxy::setName(const String& name) {
	this->name = name;
}

void Galaxy::setAddress(const String& address) {
	this->address = address;
}

void Galaxy::setPort(uint32 port) {
	this->port = port;
#ifdef USE_RANDOM_EXTRA_PORTS
	extraPorts.add(port);
#endif // USE_RANDOM_EXTRA_PORTS
}

void Galaxy::setPingPort(uint32 pingPort) {
	this->pingPort = pingPort;
}

void Galaxy::setPopulation(uint32 population) {
	this->population = population;
}

uint32 Galaxy::getID() const {
	return id;
}

const String& Galaxy::getName() const {
	return name;
}

const String& Galaxy::getAddress() const {
	return address;
}

uint32 Galaxy::getPort() const {
	return port;
}

uint32 Galaxy::getPingPort() const {
	return pingPort;
}

uint32 Galaxy::getPopulation() const {
	return population;
}

#ifdef USE_RANDOM_EXTRA_PORTS
void Galaxy::addPort(uint32 port) {
	extraPorts.add(port);
}
#endif // USE_RANDOM_EXTRA_PORTS

uint16 Galaxy::getRandomPort() const {
#ifdef USE_RANDOM_EXTRA_PORTS
	const static auto type = ConfigManager::instance()->getInt("Core3.ZonePortsBalancer", 1);

	if (type == 1) {
		static AtomicInteger roundRobin;

		return (uint16)extraPorts.get(roundRobin.increment() % extraPorts.size());
	} else {
		return (uint16)extraPorts.get(System::random(extraPorts.size() - 1));
	}
#else  // USE_RANDOM_EXTRA_PORTS
	return port;
#endif // USE_RANDOM_EXTRA_PORTS
}

bool Galaxy::toBinaryStream(ObjectOutputStream* stream) {
	return false;
}

bool Galaxy::parseFromBinaryStream(ObjectInputStream* stream) {
	return false;
}

String Galaxy::toString() const {
	StringBuffer buf;

	buf << "Galaxy("
		<< "id: " << id << ", name: " << name << ", address: " << address << ", port: " << port << ", pingPort: " << pingPort << ", population: " << population;
#ifdef USE_RANDOM_EXTRA_PORTS

	buf << ", extraPorts:";

	for (auto port : extraPorts)
		buf << " " << port;
#endif
	buf << ")";

	return buf.toString();
}

String Galaxy::toStringData() const {
	return toString();
}