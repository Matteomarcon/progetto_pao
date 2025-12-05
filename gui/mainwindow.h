#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStyle>
#include <QToolBar>
#include <QSplitter>

#include "attivita/attivita.h"
#include "Json/GestoreJson.h"
#include "xml/GestoreXml.h"
#include "vistalistaattivita.h"
#include "vistacreazioneattivita.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private slots:
    /*void mostraDettagli(Attivita*);
    void mostraViewModifica(Attivita*);
    void salvaModifica(Attivita*);
    void annulla();
    void chiudi();
    void creaNuova();
    void salvaNuova(Attivita*);
    void eliminaElemento(Attivita*);

    void salvaJson();
    void caricaJson();
    void salvaNuovoJson();
    void salvaXML();
    void caricaXML();
    void salvaNuovoXML();*/

private:
    QList<Attivita*> listaAttivita;
    QToolBar* barraStrumenti;
    QStackedWidget* stack;
    QString percorsoJson;
    QString percorsoXML;
    //pannelloRicerca* pannelloRicerca;
    VistaListaAttivita* vistaListaAttivita;
    //vistaDettagli* vistaDettagli;
    //vistaModifica* vistaModifica;
    VistaCreazioneAttivita* vistaCreazioneAttivita;
    QWidget* vistaVuota;
    bool modificheNonSalvate;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
