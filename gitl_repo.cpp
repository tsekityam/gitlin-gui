#include "gitl_repo.h"

#include <git2.h>

GITLRepo::GITLRepo(const QString &name)
{
    _name = name;
}

QString *GITLRepo::getName()
{
    return &_name;
}
