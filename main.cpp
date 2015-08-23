#include <QApplication>

#include "mainwindow.h"

#include "gitl_repo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    GITLRepo::initLibrary();

    int ret = a.exec();

    GITLRepo::shutdownLibrary();

    return ret;
}
