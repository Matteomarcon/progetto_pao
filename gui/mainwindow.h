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
#include <QCloseEvent>

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
    void apriJson();
    void salvaJson();
    void salvaComeJson();

    void apriXml();
    void salvaXml();
    void salvaComeXml();

    /*void chiudi();*/

    void mostraVistaDefault();
    void mostraVistaDettagli(Attivita*);
    void mostraVistaCreazione();
    void mostraVistaModifica(Attivita*);

    void salvaCreazione(Attivita*);
    void salvaModifica(Attivita*);
    void eliminaAttivita(Attivita*);

private:
    QList<Attivita*> listaAttivita;
    QToolBar* barraStrumenti;
    QMenu* menuApri;
    QMenu* menuSalva;
    QMenu* menuCrea;
    QStackedWidget* stack;
    QString pathJson;
    QString pathXml;
    //pannelloRicerca* pannelloRicerca;
    VistaDefault* vistaDefault;
    VistaListaAttivita* vistaListaAttivita;
    VistaDettagliAttivita* vistaDettagliAttivita;
    VistaCreazioneAttivita* vistaCreazioneAttivita;
    VistaModificaAttivita* vistaModificaAttivita;
    bool modificheNonSalvate;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
