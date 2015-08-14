#include "etacoser.h"

#include <QtGui/QPushButton>
#include <QtGui/QDesktopWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QIcon>
#include <QtGui/QPalette>

EtaCoser::EtaCoser()
{
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
    btnWindows->setIconSize(QSize(400,438));
    btnPardus->setIcon(QIcon("/usr/share/eta-coser/pardus-logo.png"));
    btnPardus->setIconSize(QSize(399,629));
    
    QPalette* background = new QPalette();
    background->setColor(QPalette::Button,"#ff6c00");
    btnPardus->setPalette(*background);	
    background->setColor(QPalette::Button,"#4AAEE8");
    btnWindows->setPalette(*background);
    
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    
    QHBoxLayout* layout = new QHBoxLayout(centralWidget);
    layout->addWidget(btnPardus);
    layout->addWidget(btnWindows);

    setCentralWidget(centralWidget);
    
    connect(btnPardus,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnWindows,SIGNAL(clicked()),this,SLOT(startWithWindows()));
}

EtaCoser::~EtaCoser()
{}

void EtaCoser::startWithWindows()
{
    system("sudo grub-reboot 2 && reboot now");
}

#include "etacoser.moc"
