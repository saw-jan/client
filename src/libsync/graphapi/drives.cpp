#include "drives.h"

using namespace OCC;
using namespace GraphApi;

Drives::Drives(const AccountPtr &account, QObject *parent)
    : JsonApiJob(account, QStringLiteral("graph/v1.0/me/drives"), parent)
{
}
