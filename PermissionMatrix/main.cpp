#include "mainwindow.h"
#include <QApplication>

//global users list (internal database)
QList<User*> USERS_LIST;
//global files list (internal database)
QList<File*> FILES_LIST;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
