#include "repocontrolwidget.h"
#include "ui_repocontrolwidget.h"

RepoControlWidget::RepoControlWidget(const GITLRepo *repo, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::RepoControlWidget)
{
    m_repo = repo;

    initializeUi();
}

RepoControlWidget::RepoControlWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::RepoControlWidget)
{
    m_repo = NULL;

    initializeUi();
}

RepoControlWidget::~RepoControlWidget()
{
    delete m_ui;

    if (m_repo) delete m_repo;
}

void RepoControlWidget::initializeUi()
{
    m_ui->setupUi(this);

    QList<int> sizes;
    sizes.append(240);
    sizes.append(720);
    m_ui->rootSplitter->setSizes(sizes);
}
