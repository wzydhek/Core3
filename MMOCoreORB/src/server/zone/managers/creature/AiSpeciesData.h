
#pragma once

#include "system/lang/String.h"
#include "system/lang/Object.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class AiSpeciesData : public Object {

protected:
	int speciesID;
	String skeleton;
	bool canSit;
	bool canLie;

public:
	AiSpeciesData(int species, String skel, bool sit, bool liedown);

	~AiSpeciesData();

	int getSpeciesID() const;

	const String& getSkeleton() const;

	bool canSitDown() const;

	bool canLieDown() const;
};

}
}
}
}

using namespace server::zone::managers::creature;