#ifndef GITLREPO_H
#define GITLREPO_H

#include <QString>

class GITLRepo
{
public:
    GITLRepo(const QString &name);

    QString *getName();

private:
    QString _name;
};

#endif // GITLREPO_H
