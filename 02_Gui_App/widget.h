#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *btn;
    QString str;
    int count;
public slots:
    void slot_btn();


};
#endif // WIDGET_H
