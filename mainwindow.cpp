#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "repocontrolwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    initializeUi();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::initializeUi()
{
    // Top Bar
        // buttons
    QObject::connect(m_ui->topButtonNewOrCloneRepo, SIGNAL(clicked(bool)), this, SLOT(slot_cloneRepo()));

    QObject::connect(m_ui->topButtonCommit, SIGNAL(clicked(bool)), this, SLOT(slot_commit()));
    QObject::connect(m_ui->topButtonPush, SIGNAL(clicked(bool)), this, SLOT(slot_push()));
    QObject::connect(m_ui->topButtonPull, SIGNAL(clicked(bool)), this, SLOT(slot_pull()));

    QObject::connect(m_ui->topButtonStash, SIGNAL(clicked(bool)), this, SLOT(slot_stash()));
    QObject::connect(m_ui->topButtonDiscard, SIGNAL(clicked(bool)), this, SLOT(slot_discard()));

    QObject::connect(m_ui->topButtonRepoSettings, SIGNAL(clicked(bool)), this, SLOT(slot_openRepoSettings()));

    QObject::connect(m_ui->topButtonTerminal, SIGNAL(clicked(bool)), this, SLOT(slot_openTerminal()));

        // menu for topButtonAddRepoExtra
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

    GITLRepo *repo = NULL;
    this->addRepoTab(*repo);
}

void MainWindow::slot_addNewRepo()
{
    qDebug("slot_addNewRepo");
}

void MainWindow::slot_addRepoFromWorkingCopy()
{
    qDebug("slot_addRepoFromWorkingCopy");

    GITLRepo *repo = new GITLRepo("Working Copy");
    this->addRepoTab(*repo);
}

void MainWindow::slot_commit()
{

}

void MainWindow::slot_push()
{
    ;
}

void MainWindow::slot_pull()
{
    ;
}

void MainWindow::slot_stash()
{
    ;
}

void MainWindow::slot_discard()
{
    ;
}

void MainWindow::slot_openRepoSettings()
{
    ;
}

void MainWindow::slot_openTerminal()
{
    ;
}

void MainWindow::addRepoTab(GITLRepo &repo)
{
    RepoControlWidget *repoTab = new RepoControlWidget(repo, this);
    const QString *tabTitle = repo.getName();
    m_ui->contentTabWidget->addTab(repoTab, tabTitle ? *tabTitle : "New Repository");
    m_ui->contentTabWidget->setCurrentWidget(repoTab);

    int indexOfStartPage = m_ui->contentTabWidget->indexOf(m_ui->contentTab_start);
    if (indexOfStartPage != -1) {
        m_ui->contentTabWidget->removeTab(indexOfStartPage);
    }
}
