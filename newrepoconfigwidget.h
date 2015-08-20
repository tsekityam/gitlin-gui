#ifndef NEWREPOCONFIGWIDGET_H
#define NEWREPOCONFIGWIDGET_H

#include <QWidget>

namespace Ui {
class NewRepoConfigWidget;
}

class NewRepoConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewRepoConfigWidget(QWidget *parent = 0);
    ~NewRepoConfigWidget();

private slots:
//    void okClicked();

private:
    Ui::NewRepoConfigWidget *m_ui;

    void initializeUi();
};

#endif // NEWREPOCONFIGWIDGET_H
