#pragma once

#include "networkjobs.h"

namespace OCC {
namespace GraphApi {


    class Drives : public JsonApiJob
    {
        Q_OBJECT
    public:
        Drives(const AccountPtr &account, QObject *parent = nullptr);
    };
}
}
