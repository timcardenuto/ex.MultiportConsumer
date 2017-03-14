#include <iostream>
#include "ossie/ossieSupport.h"

#include "MultiportConsumer.h"
int main(int argc, char* argv[])
{
    MultiportConsumer_i* MultiportConsumer_servant;
    Component::start_component(MultiportConsumer_servant, argc, argv);
    return 0;
}

