#ifndef MULTIPORTCONSUMER_BASE_IMPL_BASE_H
#define MULTIPORTCONSUMER_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>

#include <bulkio/bulkio.h>
#include <burstio/burstio.h>

class MultiportConsumer_base : public Component, protected ThreadedComponent
{
    public:
        MultiportConsumer_base(const char *uuid, const char *label);
        ~MultiportConsumer_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:

        // Ports
        /// Port: dataFloat_in
        bulkio::InFloatPort *dataFloat_in;
        /// Port: burstFloat_in
        burstio::BurstFloatIn *burstFloat_in;

    private:
};
#endif // MULTIPORTCONSUMER_BASE_IMPL_BASE_H
