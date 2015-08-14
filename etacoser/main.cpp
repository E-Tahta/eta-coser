#include <QtGui/QApplication>
#include "etacoser.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    EtaCoser etacoser;
    etacoser.show();
    return app.exec();
}
