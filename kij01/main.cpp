#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QQmlEngine>
#include <MyClass.h>



int main(int argc, char *argv[])
{

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif


    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;




    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;



    /*  qml object 연결 */
    QObject *object = engine.rootObjects()[0];
    QObject *op11 = object->findChild<QObject*>("op11");
    QObject *op12 = object->findChild<QObject*>("op12");
    QObject *op21 = object->findChild<QObject*>("op21");
    QObject *op22 = object->findChild<QObject*>("op22");







    /* db연결 */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/MYDB");
    bool isOpendDB = db.open();
    qDebug() << "main isOpendDB : " << isOpendDB;






    /*  db세팅값 받아오기  */
    QSqlQuery query(db);
    query.exec("select * from MYOP");

    int opset1;
    int opset2;

    while(query.next())
    {

       int id = query.value(0).toInt();

       if(id==1)
       {
           opset1=query.value(1).toInt();
       }
       else
       {
           opset2=query.value(1).toInt();
       }
    }



    db.close();
    QSqlDatabase::removeDatabase("db");








    /*  db세팅값에 따라 버튼 체크하기  */
    if(opset1==1)
    {
        op11->setProperty("checked",true);
    }
    else
    {
        op12->setProperty("checked",true);
    }

    if(opset2==1)
    {
        op21->setProperty("checked",true);
    }
    else
    {
        op22->setProperty("checked",true);
    }









      /*  qml-cpp signal slot 연결  */
      MyClass myClass;

      QObject::connect(object,SIGNAL(qmlSignal(int,int)), &myClass, SLOT(cppslot(int,int)));




    return app.exec();
}


