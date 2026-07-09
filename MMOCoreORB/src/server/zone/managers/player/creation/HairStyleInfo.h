/*
 * HairStyleInfo.h
 *
 *  Created on: Apr 22, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace server {
namespace zone {
namespace managers {
namespace player {
namespace creation {

class HairStyleInfo : public IffTemplate {
	String playerTemplate;
	Vector<String> styles;

public:
	HairStyleInfo();

	~HairStyleInfo();

	HairStyleInfo& operator=(const HairStyleInfo& hsi);

	/**
	 * @pre: iffStream advanced to a PTMP form.
	 */
	void readObject(IffStream* iffStream);

	bool hasStyle(const String& style) const;

	int getTotalStyles() const;

	const String& getPlayerTemplate() const;
};

}
}
}
}
}

using namespace server::zone::managers::player::creation;
