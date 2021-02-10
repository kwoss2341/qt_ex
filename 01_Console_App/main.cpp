#include <QCoreApplication>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int myVal = 100;
    qDebug()<<"hi ~~ !!!";
    qDebug("haha x %d",myVal);

    return a.exec();
}
