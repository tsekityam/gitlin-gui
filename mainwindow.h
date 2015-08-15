#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class GITLRepo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slot_addRepoFromManager();
    void slot_cloneRepo();
    void slot_addNewRepo();
    void slot_addRepoFromWorkingCopy();
    void slot_commit();
    void slot_push();
    void slot_pull();
    void slot_stash();
    void slot_discard();
    void slot_openRepoSettings();
    void slot_openTerminal();

private:
    Ui::MainWindow *m_ui;

    void initializeUi();

    void addRepoTab(GITLRepo &repo);
};

#endif // MAINWINDOW_H
