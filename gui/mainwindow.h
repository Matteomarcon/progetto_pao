#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStyle>
#include <QToolBar>
#include <QSplitter>
#include <QMenuBar>
#include <QGuiApplication>
#include <QScreen>

#include "attivita/attivita.h"
#include "Json/GestoreJson.h"
#include "xml/GestoreXml.h"
#include "vistalistaattivita.h"
#include "vistacreazioneattivita.h"
#include "vistadettagliattivita.h"
#include "vistamodificaattivita.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private slots:
    /*
    void chiudi();
    void eliminaElemento(Attivita*);

    void salvaJson();
    void caricaJson();
    void salvaNuovoJson();
    void salvaXML();
    void caricaXML();
    void salvaNuovoXML();*/

    void mostraVistaVuota();
    void mostraVistaDettagli(Attivita*);
    void mostraVistaCreazione();
    void mostraVistaModifica(Attivita*);

    void salvaCreazione(Attivita*);
    void salvaModifica(Attivita*);

private:
    QList<Attivita*> listaAttivita;
    QToolBar* barraStrumenti;
    QMenu* menuApri;
    QMenu* menuSalva;
    QMenu* menuCrea;
    QStackedWidget* stack;
    QString percorsoJson;
    QString percorsoXML;
    //pannelloRicerca* pannelloRicerca;
    VistaListaAttivita* vistaListaAttivita;
    VistaDettagliAttivita* vistaDettagliAttivita;
    VistaModificaAttivita* vistaModificaAttivita;
    VistaCreazioneAttivita* vistaCreazioneAttivita;
    QWidget* vistaVuota;
    bool modificheNonSalvate;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
