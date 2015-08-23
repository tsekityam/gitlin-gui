#include "repocontrolwidget.h"
#include "ui_repocontrolwidget.h"

#include "qstackedlayout.h"

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

    QStackedLayout *stackedLayout = new QStackedLayout(m_ui->stacked_root);
    stackedLayout->setStackingMode(QStackedLayout::StackAll);
    if (!m_repo) {
        stackedLayout->addWidget(m_ui->page_newRepo);
        QObject::connect(m_ui->newRepoWidget, SIGNAL(cancelled()), this, SLOT(slot_newReopCancelled()));
    } else {
        m_ui->page_newRepo->setHidden(true);
    }
    stackedLayout->addWidget(m_ui->page_repoControl);
    m_ui->stacked_root->setLayout(stackedLayout);

    // Repo Control Page
    QList<int> sizes;
    sizes.append(240);
    sizes.append(720);
    m_ui->splitter_repoControlRoot->setSizes(sizes);

    // New Repo Page
    m_ui->newRepoWidget->setWindowFlags(Qt::SubWindow);
}

void RepoControlWidget::setNewRepoPage(NewRepoWay way)
{
    m_ui->newRepoWidget->setNewRepoPage(way);
}

// SLOTS

void RepoControlWidget::slot_newReopCancelled()
{
    emit closeRequested((QWidget *)this);
}
