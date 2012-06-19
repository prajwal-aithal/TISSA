#include <QtGui/QApplication>
#include "tissadictionary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TISSADictionary w;
    w.show();

    return a.exec();
}
