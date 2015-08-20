#ifndef REPOCONTROLWIDGET_H
#define REPOCONTROLWIDGET_H

#include <QWidget>

#include <gitl_repo.h>

namespace Ui {
class RepoControlWidget;
}

class RepoControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RepoControlWidget(const GITLRepo *repo, QWidget *parent = 0);
    explicit RepoControlWidget(QWidget *parent = 0);
    ~RepoControlWidget();

private:
    const GITLRepo *m_repo;
    Ui::RepoControlWidget *m_ui;

    void initializeUi();
};

#endif // REPOCONTROLWIDGET_H
