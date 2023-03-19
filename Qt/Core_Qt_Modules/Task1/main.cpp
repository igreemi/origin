#include <QCoreApplication>
#include <QTcpSocket>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket soc;

    QSqlDatabase DB;

    return a.exec();
}
