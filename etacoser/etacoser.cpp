#include "etacoser.h"

#include <QtGui/QPushButton>
#include <QtGui/QDesktopWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QIcon>
#include <QtGui/QPalette>
#include <QSettings>

EtaCoser::EtaCoser()
{
    QSettings settings("/usr/share/eta-coser/config.ini",QSettings::IniFormat);
    settings.beginGroup("eta-coser");
    operatingsystem = settings.value("Start").toString();
    if(operatingsystem=="Pardus")
    {
        startwithpardusflag = true;
    }
    else
    {
        startwithpardusflag = false;
    }

    time = settings.value("Time").toInt();
    settings.endGroup();

    QDesktopWidget dw;
    int sw = dw.screenGeometry(dw.primaryScreen()).width();
    int sh = dw.screenGeometry(dw.primaryScreen()).height();
    
    setWindowFlags(Qt::X11BypassWindowManagerHint);
    resize(sw,sh);
    
    QPushButton* btnPardus = new QPushButton(this);
    QPushButton* btnWindows = new QPushButton(this);
    
    btnPardus->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    btnWindows->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    
    btnWindows->setIcon(QIcon("/usr/share/eta-coser/windows-logo.png"));
    btnWindows->setIconSize(QSize(328,337));
    btnPardus->setIcon(QIcon("/usr/share/eta-coser/pardus-logo.png"));
    btnPardus->setIconSize(QSize(304,373));

    btnPardus->setStyleSheet( "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #ffcc00, stop:1 #ff9c00);");
    
    btnWindows->setStyleSheet( "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #56c4ff, stop:1 #006ac0);");

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    centralWidget->setGeometry(0,0,sw,sh-50);
    
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);
    layout->addWidget(btnPardus);
    layout->addWidget(btnWindows);

    statuslabel = new QLabel(this);
    statuslabel->setGeometry(0,sh-50,sw,50);
    statuslabel->setStyleSheet("QLabel{color: black; qproperty-alignment: AlignCenter;}");
    QFont f;
    f.setPointSize(30);
    statuslabel->setFont(f);

    countdown = new QTimer(this);
    connect(countdown,SIGNAL(timeout()),this,SLOT(setTime()));
    connect(btnPardus,SIGNAL(clicked()),this,SLOT(startWithPardus()));
    connect(btnWindows,SIGNAL(clicked()),this,SLOT(startWithWindows()));

    QTimer::singleShot(time*1000,this,SLOT(timerShotCallBack()));

    countdown->start(1000);
    setStatusLabel(time--);
}

EtaCoser::~EtaCoser()
{}

void EtaCoser::startWithWindows()
{
    system("sudo grub-reboot 2 && reboot now");
}

void EtaCoser::startWithPardus()
{
    this->close();
}

void EtaCoser::timerShotCallBack()
{
    if(startwithpardusflag)
    {
        startWithPardus();
    }
    else
    {
        startWithWindows();
    }

}

void EtaCoser::setTime()
{
    if(time == 0)
    {
        countdown->stop();
    }
    else
    {
        setStatusLabel(time--);
    }
}

void EtaCoser::setStatusLabel(int seconds)
{
    QString output = operatingsystem+ QString::fromUtf8(" Açılıyor ")+ QString::number(seconds);
    statuslabel->setText( output);
}
