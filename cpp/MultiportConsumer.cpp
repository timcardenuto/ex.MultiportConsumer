/**************************************************************************

    This is the component code. This file contains the child class where
    custom functionality can be added to the component. Custom
    functionality to the base class can be extended here. Access to
    the ports can also be done from this class

**************************************************************************/

#include "MultiportConsumer.h"

PREPARE_LOGGING(MultiportConsumer_i)

MultiportConsumer_i::MultiportConsumer_i(const char *uuid, const char *label) :
    MultiportConsumer_base(uuid, label)
{
    // Avoid placing constructor code here. Instead, use the "constructor" function.

}

MultiportConsumer_i::~MultiportConsumer_i()
{
}

void MultiportConsumer_i::constructor()
{
}

int MultiportConsumer_i::serviceFunction()
{
	burstio::BurstFloatIn::PacketType *pkt;
	pkt = burstFloat_in->getBurst(bulkio::Const::NON_BLOCKING);
	if (pkt == NULL) {
		return NOOP;
	}

	std::cout << this->naming_service_name << "\n";
	std::cout << "	Received Data:	\n	";
	for (unsigned int i=0; i < pkt->getSize(); i++) {
		std::cout << (float)pkt->getData()[i] << " ";
	}
	std::cout << "\n";
	std::string stringvalue;
	std::cout << "	Received Keywords: \n";

	if (pkt->getSRI().keywords[0].value >>= stringvalue) {
		std::cout << "	ID: " << pkt->getSRI().keywords[0].id << "   Value: " << stringvalue << std::endl;
	}

	if (pkt->getSRI().keywords[1].value >>= stringvalue) {
		std::cout << "	ID: " << pkt->getSRI().keywords[1].id << "   Value: " << stringvalue << std::endl;
	}
	std::cout << "\n";

	return NORMAL;
}

