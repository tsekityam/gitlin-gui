#include "gitl_repo.h"

#include <git2.h>

GITLRepo::GITLRepo(const QString &name)
{
    _name = name;
    _repo = NULL;

    git_libgit2_init();
}

GITLRepo::~GITLRepo()
{
    git_libgit2_shutdown();
}

QString *GITLRepo::getName()
{
    return &_name;
}

bool GITLRepo::clone(const QString &repoUrl, const QString &destPath)
{
    return git_clone(&_repo, repoUrl.toUtf8().data(), destPath.toUtf8().data(), NULL) == 0;
}
