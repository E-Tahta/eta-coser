QT       += core gui widgets

RESOURCES += images.qrc

TARGET = eta-coser
TEMPLATE = app


SOURCES += main.cpp \
    eta-coser.cpp

HEADERS  += \
    eta-coser.h

target.path = /usr/bin/

config_files.files = config.ini Xsetup.modified
config_files.commands = mkdir -p /usr/share/eta/eta-coser
config_files.path = /usr/share/eta/eta-coser/

INSTALLS += target config_files
