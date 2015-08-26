#ifndef GITLREPO_H
#define GITLREPO_H

#include <QString>

struct git_repository;

class GITLRepo
{
public:
    static void initLibrary();
    static void shutdownLibrary();

    static void getLastErrorMessage(QString **errorMsg);

    GITLRepo(const QString &name);
    ~GITLRepo();

    QString *getName();

    bool clone(const QString &repoUrl, const QString &destPath);

private:
    git_repository *_repo;

    QString _name;
};

#endif // GITLREPO_H
