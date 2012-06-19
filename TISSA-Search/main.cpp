#include <QtGui/QApplication>
#include "tissasearch.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TISSASearch w;
    w.show();

    return a.exec();
}
