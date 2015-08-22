#ifndef REPOCONTROLWIDGET_H
#define REPOCONTROLWIDGET_H

#include <QWidget>

#include "newrepoconfigwidget.h"

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

    void setNewRepoPage(NewRepoWay way);

private:
    const GITLRepo *m_repo;
    Ui::RepoControlWidget *m_ui;

    void initializeUi();

signals:
    void closeRequested(QWidget *thisWidget);

private slots:
    void slot_newReopCancelled();

};

#endif // REPOCONTROLWIDGET_H
