#include "etacoser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EtaCoser w;
    w.show();

    return a.exec();
}
