#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStyle>
#include <QToolBar>

#include "Attivita/attivita.h"

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
    QStackedWidget stack;
    QString percorsoJson;
    QString percorsoXML;
    //pannelloRicerca* pannelloRicerca;
    //vistaLista* vistaLista;
    //vistaDettagli* vistaDettagli;
    //vistaModifica* vistaModifica;
    //vistaCreazione* vistaCreazione;
    QWidget* vistaVuota;
    bool modificheNonSalvate;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
