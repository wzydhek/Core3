#include "SceneObjectCloseMessage.h"

SceneObjectCloseMessage::SceneObjectCloseMessage(const SceneObject* scno) : BaseMessage(18) {
	insertShort(0x02);
	insertInt(0x2C436037);									   // CRC
	insertLong(const_cast<SceneObject*>(scno)->getObjectID()); // ObjectID

	/*StringBuffer msg;
	msg << hex << "SceneObjectCloseMessage [Object = " << scno->getObjectID() << "]" << " of (" << scno->getObjectCRC() << ")\n";
	System::out << msg.toString();*/
}

SceneObjectCloseMessage::SceneObjectCloseMessage(uint64 oid) : BaseMessage() {
	insertShort(0x02);
	insertInt(0x2C436037); // CRC
	insertLong(oid);	   // ObjectID

	/*StringBuffer msg;
	msg << hex << "SceneObjectCloseMessage [Object = " << oid  << "]\n";
	System::out << msg.toString(); */
}