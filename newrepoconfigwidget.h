#ifndef NEWREPOCONFIGWIDGET_H
#define NEWREPOCONFIGWIDGET_H

#include <QWidget>

#include <QAbstractButton>

#include "gitl_repo.h"

namespace Ui {
class NewRepoConfigWidget;
}

class NewRepoConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewRepoConfigWidget(QWidget *parent = 0);
    ~NewRepoConfigWidget();

private:
    Ui::NewRepoConfigWidget *m_ui;

    void initializeUi();

signals:
    void repoCreated(GITLRepo *repo);
    void cancelled();

private slots:
    void slot_ok();
    void slot_cancel();
};

#endif // NEWREPOCONFIGWIDGET_H
