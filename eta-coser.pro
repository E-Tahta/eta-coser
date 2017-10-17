QT       += core gui widgets

RESOURCES += images.qrc

TARGET = eta-coser
TEMPLATE = app


SOURCES += main.cpp \
    eta-coser.cpp

HEADERS  += \
    eta-coser.h

target.path = /usr/bin/

config_files.files = config.ini 30_eta-coser.conf
config_files.commands = mkdir -p /usr/share/eta/eta-coser
config_files.path = /usr/share/eta/eta-coser/

wrapper_file.files = eta-coser-wrapper.sh
wrapper_file.path = /usr/bin/

INSTALLS += target config_files wrapper_file
