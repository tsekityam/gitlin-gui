#include "repocontrolwidget.h"
#include "ui_repocontrolwidget.h"

RepoControlWidget::RepoControlWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::RepoControlWidget)
{
    m_ui->setupUi(this);

    initializeUi();
}

RepoControlWidget::~RepoControlWidget()
{
    delete m_ui;
}

void RepoControlWidget::initializeUi()
{
    QList<int> sizes;
    sizes.append(240);
    sizes.append(720);
    m_ui->rootSplitter->setSizes(sizes);
}
