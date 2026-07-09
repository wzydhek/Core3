#include "ImageDesignMessage.h"

ImageDesignStartMessage::ImageDesignStartMessage(CreatureObject* object, CreatureObject* designer, CreatureObject* targetPlayer, uint64 tentID, const String& holoemote) : ObjectControllerMessage(object->getObjectID(), 0x1B, 0x023A) {
	insertLong(designer->getObjectID());	 // Image Designer
	insertLong(targetPlayer->getObjectID()); // Image Design Target
	insertLong(tentID);
	// insertShort(type); // 0 = designer, 1 = target <-- research this
	insertAscii(holoemote);
}

ImageDesignRejectMessage::ImageDesignRejectMessage(uint64 object, uint64 designer, uint64 client, uint64 tent, int type) : ObjectControllerMessage(object, 0x1B, 0x0239) {
	insertLong(designer); // Image Designer?
	insertLong(client);	  // Image Design Target
	insertLong(tent);	  // Boolish - in an ID tent? or a cell id?
	insertByte(type);	  // 0 = designer, 1 = target
}

ImageDesignChangeMessage::ImageDesignChangeMessage(uint64 object, uint64 designer, uint64 client, uint64 tent, int type) : ObjectControllerMessage(object, 0x1B, 0x0238) {
	insertLong(designer); // Image Designer?
	insertLong(client);	  // Image Design Target
	insertLong(tent);	  // Boolish - in an ID tent? or a cell id?
	insertByte(type);	  // 0 = designer, 1 = target
}