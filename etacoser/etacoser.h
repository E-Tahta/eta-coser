#ifndef etacoser_H
#define etacoser_H

#include <QtGui/QMainWindow>

class EtaCoser : public QMainWindow
{
    Q_OBJECT

public:
    EtaCoser();
    virtual ~EtaCoser();
private:
    bool startwithpardusflag;
private slots:
    void startWithWindows();
    void startWithPardus();
    void timerShotCallBack();
};

#endif // etacoser_H
