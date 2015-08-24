#include "newrepoconfigwidget.h"
#include "ui_newrepoconfigwidget.h"

#include <QMessageBox>

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

//    QObject::connect(m_ui->pushButton_clone_src_test, SIGNAL(clicked(bool)), this, SLOT(slot_testCloneRemote()));
}

void NewRepoConfigWidget::setNewRepoPage(NewRepoWay way)
{
    m_ui->tabWidget_root->setCurrentIndex(way);
}

// SLOTS

void NewRepoConfigWidget::slot_ok()
{

}

void NewRepoConfigWidget::slot_cancel()
{
    emit cancelled();
}

/*void NewRepoConfigWidget::slot_testCloneRemote()
{
    QMessageBox *messageBox = NULL;

    if (m_ui->lineEdit_clone_src->text().length() == 0) {
        messageBox = new QMessageBox(QMessageBox::Critical, "Error", "Cannot test empty path");

        goto showMessageBox;
    }

    if (GITLRepo::checkRemoteValidity(m_ui->lineEdit_clone_src->text())) {
        messageBox = new QMessageBox(QMessageBox::Information, "Success", "Test Remote Successful");

        goto showMessageBox;
    } else {
        QString *errMsgPtr;
        GITLRepo::getLastErrorMessage(&errMsgPtr);
        messageBox = new QMessageBox(QMessageBox::Critical, "Error", *errMsgPtr);
        delete errMsgPtr;

        goto showMessageBox;
    }

    showMessageBox:
    messageBox->setAttribute(Qt::WA_DeleteOnClose, true);
    messageBox->show();
}*/
