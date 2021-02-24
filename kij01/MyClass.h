#ifndef MYCLASS_H
#define MYCLASS_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT

private:

    QSqlDatabase db;



    public slots:
    void cppslot(const int a,const int b);



    public:
    MyClass(){

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/home/pi/MYDB");


        bool isOpendDB = db.open();
        qDebug() << "class isOpendDB : " << isOpendDB;


        /*
        QSqlQuery query(db);
        query.exec("select * from MYOP");


        while(query.next())
        {
           QString i = query.value(1).toString();
           qDebug()<<i;
        }*/


    }

    ~MyClass(){

        db.close();
        QSqlDatabase::removeDatabase("db");

    }




};

#endif // COUNTER_H
