#ifndef etacoser_H
#define etacoser_H

#include <QtGui/QMainWindow>
#include <QtGui/QLabel>
#include <QTimer>

class EtaCoser : public QMainWindow
{
    Q_OBJECT

public:
    EtaCoser();
    virtual ~EtaCoser();
private:
    bool startwithpardusflag;
    int time;
    QLabel * statuslabel;
    QTimer *countdown;
    QString operatingsystem;
private slots:
    void startWithWindows();
    void startWithPardus();
    void timerShotCallBack();
    void setStatusLabel(int seconds);
    void setTime();
};

#endif // etacoser_H
