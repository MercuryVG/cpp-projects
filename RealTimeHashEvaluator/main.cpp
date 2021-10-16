#include "realtimehash.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RealTimeHash w;
    w.show();
    return a.exec();
}
