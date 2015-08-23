#include "gitl_repo.h"

#include <git2.h>

GITLRepo::GITLRepo(const QString &name)
{
    _name = name;

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

void GITLRepo::clone(const QString &repoUrl, const QString &destPath)
{
    git_repository *repo = NULL;
    git_clone(&repo, repoUrl.toUtf8().data(), destPath.toUtf8().data(), NULL);
}
