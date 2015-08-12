#ifndef REPOCONTROLWIDGET_H
#define REPOCONTROLWIDGET_H

#include <QWidget>

namespace Ui {
class RepoControlWidget;
}

class RepoControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RepoControlWidget(QWidget *parent = 0);
    ~RepoControlWidget();

private:
    Ui::RepoControlWidget *m_ui;

    void initializeUi();
};

#endif // REPOCONTROLWIDGET_H
