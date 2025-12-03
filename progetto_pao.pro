QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attivita/Attivita.cpp \
    attivita/evento.cpp \
    attivita/impegno.cpp \
    attivita/promemoria.cpp \
    attivita/riunione.cpp \
    attivita/viaggio.cpp \
    gui/Mainwindow.cpp \
    json/JsonHandler.cpp \
    main.cpp \
    xml/XMLHandler.cpp

HEADERS += \
    attivita/Attivita.h \
    attivita/VisitorInterface.h \
    attivita/VisitorModifica.h \
    attivita/evento.h \
    attivita/impegno.h \
    attivita/promemoria.h \
    attivita/riunione.h \
    attivita/viaggio.h \
    gui/Mainwindow.h \
    json/JsonHandler.h \
    xml/XMLHandler.h

FORMS += \
    gui/Mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
