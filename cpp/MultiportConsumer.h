#ifndef MULTIPORTCONSUMER_I_IMPL_H
#define MULTIPORTCONSUMER_I_IMPL_H

#include "MultiportConsumer_base.h"

class MultiportConsumer_i : public MultiportConsumer_base
{
    ENABLE_LOGGING
    public:
        MultiportConsumer_i(const char *uuid, const char *label);
        ~MultiportConsumer_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // MULTIPORTCONSUMER_I_IMPL_H
