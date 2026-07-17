/*
			Copyright <SWGEmu>
	See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

// #define USE_RANDOM_EXTRA_PORTS
#ifdef USE_RANDOM_EXTRA_PORTS
	#include "conf/ConfigManager.h"
#endif // USE_RANDOM_EXTRA_PORTS

namespace server {
namespace login {
namespace objects {

class Galaxy {
	uint32 id = 0;
	String name;
	String address;
	uint32 port = 0;
	uint32 pingPort = 0;
	uint32 population = 0;
#ifdef USE_RANDOM_EXTRA_PORTS
	Vector<uint32> extraPorts;
#endif // USE_RANDOM_EXTRA_PORTS
public:
	Galaxy() = default;

	Galaxy(ResultSet* result);

	Galaxy(uint32 id);

	void setID(uint32 id);

	void setName(const String& name);

	void setAddress(const String& address);

	void setPort(uint32 port);

	void setPingPort(uint32 pingPort);

	void setPopulation(uint32 population);

	uint32 getID() const;

	const String& getName() const;

	const String& getAddress() const;

	uint32 getPort() const;

	uint32 getPingPort() const;

	uint32 getPopulation() const;

#ifdef USE_RANDOM_EXTRA_PORTS
	void addPort(uint32 port);
#endif // USE_RANDOM_EXTRA_PORTS

	uint16 getRandomPort() const;

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	String toString() const;

	String toStringData() const;
};

} // namespace objects
} // namespace login
} // namespace server

using namespace server::login::objects;
