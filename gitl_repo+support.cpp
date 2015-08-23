#include "gitl_repo.h"

#include <git2.h>
#include <git2/sys/repository.h>

#include <QDebug>

void GITLRepo::initLibrary()
{
    git_libgit2_init();
}

void GITLRepo::shutdownLibrary()
{
    git_libgit2_shutdown();
}

bool GITLRepo::checkRemoteValidity(const QString &remoteUrl)
{

    git_repository *repo = NULL;
    git_remote *remote = NULL;
//    git_remote_callbacks callbacks = GIT_REMOTE_CALLBACKS_INIT;

    int err = 0;

    err = git_repository_new(&repo);
    if (err)
        goto cleanup;

    err = git_remote_create_anonymous(&remote, repo, remoteUrl.toUtf8().data());
    if (err)
        goto cleanup;

    err = git_remote_connect(remote, GIT_DIRECTION_FETCH, NULL);
    if (err)
        goto cleanup;

    cleanup:
    git_remote_free(remote);

    QString *errMsg = NULL;
    GITLRepo::getLastErrorMessage(&errMsg);
    qDebug() << "err: " << err << *errMsg;
    delete errMsg;

    return err == 0;
}

void GITLRepo::getLastErrorMessage(QString **errorMsg)
{
    *errorMsg = new QString(giterr_last()->message);
}

