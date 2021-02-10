#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <string>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300,200);

    str=QString("Hello World");
    btn=new QPushButton(str,this);
    btn->setGeometry(10,10,100,30);

    count=0;

    connect(btn, &QPushButton::clicked ,this,&Widget::slot_btn);

}

void Widget::slot_btn()
{
    count++;
    std::string s = std::to_string(count)+" 번";
    const char *a=s.c_str();
    btn->setText(QString(a));

}

Widget::~Widget()
{
}

