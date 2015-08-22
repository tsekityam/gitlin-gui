#ifndef NEWREPOCONFIGWIDGET_H
#define NEWREPOCONFIGWIDGET_H

#include <QWidget>

#include <QAbstractButton>

#include "gitl_repo.h"

namespace Ui {
class NewRepoConfigWidget;
}

typedef enum {
    CLONE = 0,
    WORKING_COPY = 1,
    LOCAL_FILES = 2
} NewRepoWay;

class NewRepoConfigWidget : public QWidget
{

    Q_OBJECT

public:
    explicit NewRepoConfigWidget(QWidget *parent = 0);
    ~NewRepoConfigWidget();

    void setNewRepoPage(NewRepoWay way);
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
