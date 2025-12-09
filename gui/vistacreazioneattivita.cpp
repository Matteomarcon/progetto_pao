#include "vistacreazioneattivita.h"

VistaCreazioneAttivita::VistaCreazioneAttivita(QWidget *parent): QWidget{parent} {
    QLabel* labelTitolo = new QLabel("Crea una nuova attività:");
    labelTitolo->setAlignment(Qt::AlignCenter);

    tipoAttivita = new QComboBox();
    tipoAttivita->addItem("Evento");
    tipoAttivita->addItem("Lettura");
    tipoAttivita->addItem("Promemoria");
    tipoAttivita->addItem("Riunione");
    tipoAttivita->addItem("Viaggio");

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneSalva = new QPushButton("Crea Attività");
    bottoneAnnulla = new QPushButton("Annulla");

    layoutBottoni->addWidget(bottoneSalva);
    layoutBottoni->addWidget(bottoneAnnulla);

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutForm = new QVBoxLayout(this);
    layoutPrincipale->addWidget(labelTitolo);
    layoutPrincipale->addWidget(tipoAttivita);
    layoutPrincipale->addLayout(layoutForm);
    layoutPrincipale->addStretch();
    layoutPrincipale->addLayout(layoutBottoni);
}

void VistaCreazioneAttivita::creaAttivita() {

}
void VistaCreazioneAttivita::creaAttivitaProgrammata() {

}
void VistaCreazioneAttivita::creaAttivitaLibera() {

}
void VistaCreazioneAttivita::creaEvento() {
    creaAttivitaProgrammata();

}
void VistaCreazioneAttivita::creaLettura() {
    creaAttivitaLibera();

    campiForm["autore"] = new QLineEdit();
    QSpinBox* pagine = new QSpinBox();
    pagine->setMinimum(1);
    campiForm["pagine"] = pagine;
    campiForm["lingua"] = new QLineEdit();

    layoutForm->addWidget(new QLabel("Autore"));
    layoutForm->addWidget(campiForm["autore"]);
    layoutForm->addWidget(new QLabel("Numero di pagine"));
    layoutForm->addWidget(campiForm["pagine"]);
    layoutForm->addWidget(new QLabel("Lingua"));
    layoutForm->addWidget(campiForm["lingua"]);
}
void VistaCreazioneAttivita::creaPromemoria() {
    creaAttivitaLibera();

    campiForm["nota"] = new QLineEdit();

    layoutForm->addWidget(new QLabel("Nota"));
    layoutForm->addWidget(campiForm["nota"]);
}
void VistaCreazioneAttivita::creaRiunione() {
    creaAttivitaProgrammata();

}
void VistaCreazioneAttivita::creaViaggio() {
    creaAttivitaProgrammata();

}

void VistaCreazioneAttivita::pulisciLayout(QLayout*) {

}

Attivita* VistaCreazioneAttivita::creaOggettoAttivita() {

}
