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
#include <QFileDialog>

#include "attivita/attivita.h"
#include "Json/GestoreJson.h"
#include "xml/GestoreXml.h"
#include "vistadefault.h"
#include "vistalistaattivita.h"
#include "vistacreazioneattivita.h"
#include "vistadettagliattivita.h"
#include "vistamodificaattivita.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private slots:
    void salvaJson();
    /*
    void chiudi();
    void eliminaElemento(Attivita*);

    void caricaJson();
    void salvaNuovoJson();
    void salvaXML();
    void caricaXML();
    void salvaNuovoXML();*/

    void mostraVistaDefault();
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
    QString pathJson;
    QString pathXML;
    //pannelloRicerca* pannelloRicerca;
    VistaDefault* vistaDefault;
    VistaListaAttivita* vistaListaAttivita;
    VistaDettagliAttivita* vistaDettagliAttivita;
    VistaModificaAttivita* vistaModificaAttivita;
    VistaCreazioneAttivita* vistaCreazioneAttivita;
    bool modificheNonSalvate;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
