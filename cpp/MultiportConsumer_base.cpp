#include "MultiportConsumer_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

MultiportConsumer_base::MultiportConsumer_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    setThreadName(label);

    loadProperties();

    dataFloat_in = new bulkio::InFloatPort("dataFloat_in");
    dataFloat_in->setLogger(this->_baseLog->getChildLogger("dataFloat_in", "ports"));
    addPort("dataFloat_in", dataFloat_in);
    burstFloat_in = new burstio::BurstFloatIn("burstFloat_in");
    burstFloat_in->setLogger(this->_baseLog->getChildLogger("burstFloat_in", "ports"));
    addPort("burstFloat_in", burstFloat_in);
}

MultiportConsumer_base::~MultiportConsumer_base()
{
    dataFloat_in->_remove_ref();
    dataFloat_in = 0;
    burstFloat_in->_remove_ref();
    burstFloat_in = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void MultiportConsumer_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void MultiportConsumer_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void MultiportConsumer_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void MultiportConsumer_base::loadProperties()
{
}



