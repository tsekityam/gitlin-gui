#include "newrepoconfigwidget.h"
#include "ui_newrepoconfigwidget.h"

NewRepoConfigWidget::NewRepoConfigWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::NewRepoConfigWidget)
{
    m_ui->setupUi(this);

    initializeUi();
}

NewRepoConfigWidget::~NewRepoConfigWidget()
{
    delete m_ui;
}

void NewRepoConfigWidget::initializeUi()
{
    m_ui->tabWidget_root->setTabIcon(0, QIcon(":/res/img/tabIcon_repo_clone"));
    m_ui->tabWidget_root->setTabIcon(1, QIcon(":/res/img/tabIcon_repo_clone"));
    m_ui->tabWidget_root->setTabIcon(2, QIcon(":/res/img/tabIcon_repo_clone"));

    QObject::connect(m_ui->buttonBox_ok, SIGNAL(accepted()), this, SLOT(slot_ok()));
    QObject::connect(m_ui->buttonBox_ok, SIGNAL(rejected()), this, SLOT(slot_cancel()));
}

void NewRepoConfigWidget::slot_ok()
{

}

void NewRepoConfigWidget::slot_cancel()
{
    emit cancelled();
}
