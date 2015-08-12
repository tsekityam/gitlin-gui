#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

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

private:
    Ui::MainWindow *m_ui;

    void initTopBar();
};

#endif // MAINWINDOW_H
