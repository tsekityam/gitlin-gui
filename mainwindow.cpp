#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    initTopBar();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::initTopBar()
{
    // Add menu for topButtonAddRepoExtra
    QMenu *menu = new QMenu(m_ui->topButtonAddRepoExtra);

    QAction *action = new QAction("Open from Repository Manager...", menu);
    QObject::connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_addRepoFromManager()));
    menu->addAction(action);

    menu->addSeparator();

    action = new QAction("Clone...", menu);
    QObject::connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_cloneRepo()));
    menu->addAction(action);

    action = new QAction("New...", menu);
    QObject::connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_addNewRepo()));
    menu->addAction(action);

    action = new QAction("Add from Existing Working Copy...", menu);
    QObject::connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_addRepoFromWorkingCopy()));
    menu->addAction(action);

    m_ui->topButtonAddRepoExtra->setMenu(menu);
}

void MainWindow::slot_addRepoFromManager()
{
    qDebug("slot_addRepoFromManager");
}

void MainWindow::slot_cloneRepo()
{
    qDebug("slot_cloneRepo");
}

void MainWindow::slot_addNewRepo()
{
    qDebug("slot_addNewRepo");
}

void MainWindow::slot_addRepoFromWorkingCopy()
{
    qDebug("slot_addRepoFromWorkingCopy");
}
