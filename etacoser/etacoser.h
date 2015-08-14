#ifndef etacoser_H
#define etacoser_H

#include <QtGui/QMainWindow>

class EtaCoser : public QMainWindow
{
    Q_OBJECT

public:
    EtaCoser();
    virtual ~EtaCoser();
private slots:
    void startWithWindows();
};

#endif // etacoser_H
