#ifndef GITLREPO_H
#define GITLREPO_H

#include <QString>

class GITLRepo
{
public:
    static void initLibrary();
    static void shutdownLibrary();

//    static bool checkRemoteValidity(const QString &remoteUrl);
    static void getLastErrorMessage(QString **errorMsg);

    GITLRepo(const QString &name);
    ~GITLRepo();

    QString *getName();

    void clone(const QString &repoUrl, const QString &destPath);

private:
    QString _name;
};

#endif // GITLREPO_H
