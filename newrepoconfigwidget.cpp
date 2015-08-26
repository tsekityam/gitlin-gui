#include "newrepoconfigwidget.h"
#include "ui_newrepoconfigwidget.h"

#include <QInputDialog>
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

bool NewRepoConfigWidget::isVaildInput(QString **errMsg)
{
    int currentPageIndex = m_ui->tabWidget_root->currentIndex();

    if (currentPageIndex == 0) { // Clone
        if (m_ui->lineEdit_clone_src->text().length() == 0) {
            *errMsg = new QString("Clone source path / URL must not be empty.");
            return false;
        }

        if (m_ui->lineEdit_clone_dest->text().length() == 0) {
            *errMsg = new QString("Clone destination path must not be empty.");
            return false;
        }

        return true;
    }

    return true;
}

void NewRepoConfigWidget::setNewRepoPage(NewRepoWay way)
{
    m_ui->tabWidget_root->setCurrentIndex(way);
}

// SLOTS

void NewRepoConfigWidget::slot_ok()
{
    int currentPageIndex;
    bool success;

    QString repoName;
    GITLRepo *repo;
    QString *errMsg = NULL;

    success = isVaildInput(&errMsg);
    if (!success)
        goto error;

    repoName = QInputDialog::getText(this, "Input Repository Name", "Repository Name", QLineEdit::Normal, "", &success);
    if (!success)
        goto error;

    repo = new GITLRepo(repoName);
    currentPageIndex = m_ui->tabWidget_root->currentIndex();
    if (currentPageIndex == 0) { // Clone
        success = repo->clone(m_ui->lineEdit_clone_src->text(), m_ui->lineEdit_clone_dest->text());
    }
    if (!success) {
        GITLRepo::getLastErrorMessage(&errMsg);
        goto error;
    }

    emit repoCreated(repo);
    return;

    error:
    if (errMsg) {
        QMessageBox *messageBox = new QMessageBox(QMessageBox::Critical, "Error", *errMsg);
        messageBox->setAttribute(Qt::WA_DeleteOnClose, true);
        messageBox->exec();

        delete errMsg;
    }
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
