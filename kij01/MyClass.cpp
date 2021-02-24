#include "MyClass.h"
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
void MyClass::cppslot(const int a,const int b)
{


        /*  qml 시그널에 따라 db값 변경  */


        QSqlQuery query(db);

        if(a==1)
        {
            if(b==1)
            {
                qDebug()<<"1-1";
                query.exec("update MYOP set setting = 1 where id = 1");
            }
            else
            {
                qDebug()<<"1-2";
                query.exec("update MYOP set setting = 2 where id = 1");
            }
        }
        else
        {
            if(b==1)
            {
                qDebug()<<"2-1";
                query.exec("update MYOP set setting = 1 where id = 2");
            }
            else
            {
                qDebug()<<"2-2";
                query.exec("update MYOP set setting = 2 where id = 2");
            }
        }






}

