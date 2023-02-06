#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class ToolBar : public QWidget
{
    Q_OBJECT

public:

    explicit ToolBar(QWidget *parent = nullptr);

    QPushButton* Run;
    QPushButton* Clear;

signals:

private:

    QHBoxLayout* HBoxLayout;
};

#endif // TOOLBAR_H
