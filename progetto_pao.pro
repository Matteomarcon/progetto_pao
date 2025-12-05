QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attivita/attivita.cpp \
    attivita/attivitalibera.cpp \
    attivita/attivitaprogrammata.cpp \
    attivita/evento.cpp \
    attivita/lettura.cpp \
    attivita/promemoria.cpp \
    attivita/riunione.cpp \
    attivita/viaggio.cpp \
    gui/mainwindow.cpp \
    gui/visitorlista.cpp \
    gui/vistacreazioneattivita.cpp \
    gui/vistalistaattivita.cpp \
    json/GestoreJson.cpp \
    main.cpp \
    xml/GestoreXml.cpp

HEADERS += \
    attivita/VisitorInterface.h \
    attivita/VisitorModifica.h \
    attivita/attivita.h \
    attivita/attivitalibera.h \
    attivita/attivitaprogrammata.h \
    attivita/evento.h \
    attivita/lettura.h \
    attivita/promemoria.h \
    attivita/riunione.h \
    attivita/viaggio.h \
    gui/mainwindow.h \
    gui/visitorlista.h \
    gui/vistacreazioneattivita.h \
    gui/vistalistaattivita.h \
    json/GestoreJson.h \
    xml/GestoreXml.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone.qrc
