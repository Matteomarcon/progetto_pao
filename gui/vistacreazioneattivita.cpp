#include "vistacreazioneattivita.h"
#include <QDateTimeEdit>

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
    pulisciLayout(layoutForm);
    campiForm.clear();
    QString tipo = tipoAttivita->currentText();

    if (tipo == "Evento") {
        creaEvento();
    } else if (tipo == "Lettura") {
        creaLettura();
    } else if (tipo == "Promemoria") {
        creaPromemoria();
    } else if (tipo == "Riunione") {
        creaRiunione();
    } else if (tipo == "Viaggio") {
        creaViaggio();
    }
}
void VistaCreazioneAttivita::creaAttivitaProgrammata() {
    campiForm["titolo"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Titolo"));
    layoutForm->addWidget(campiForm["titolo"]);

    campiForm["descrizionebreve"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Breve descrizione"));
    layoutForm->addWidget(campiForm["descrizionebreve"]);

    QDateTimeEdit* dataInizio = new QDateTimeEdit();
    dataInizio->setCalendarPopup(true);
    dataInizio->setDateTime(QDateTime::currentDateTime());
    campiForm["datainizio"] = dataInizio;
    layoutForm->addWidget(new QLabel("Data inizio"));
    layoutForm->addWidget(campiForm["datainizio"]);

    QDateTimeEdit* dataFine = new QDateTimeEdit();
    dataFine->setCalendarPopup(true);
    dataFine->setDateTime(QDateTime::currentDateTime().addSecs(3600)); // aggiunge un ora di default
    campiForm["datafine"] = dataFine;
    layoutForm->addWidget(new QLabel("Data fine"));
    layoutForm->addWidget(campiForm["datafine"]);
}
void VistaCreazioneAttivita::creaAttivitaLibera() {
    campiForm["titolo"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Titolo"));
    layoutForm->addWidget(campiForm["titolo"]);

    campiForm["descrizioneBreve"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Breve descrizione"));
    layoutForm->addWidget(campiForm["descrizionebreve"]);

    QComboBox* stato = new QComboBox();
    stato->addItem("Non iniziata");
    stato->addItem("In corso");
    stato->addItem("Completata");
    campiForm["stato"] = stato;
    layoutForm->addWidget(new QLabel("Stato"));
    layoutForm->addWidget(campiForm["stato"]);

    QSpinBox* priorita = new QSpinBox();
    priorita->setMinimum(1);
    priorita->setMaximum(5); // da 1 a 5 con 1 bassa e 5 alta
    campiForm["priorita"] = priorita;
    layoutForm->addWidget(new QLabel("Priorità (1-5)"));
    layoutForm->addWidget(campiForm["priorita"]);
}

void VistaCreazioneAttivita::creaEvento() {
    creaAttivitaProgrammata();

    campiForm["organizzatore"] = new QLineEdit();
    campiForm["luogo"] = new QLineEdit();

    layoutForm->addWidget(new QLabel("Organizzatore"));
    layoutForm->addWidget(campiForm["organizzatore"]);
    layoutForm->addWidget(new QLabel("Luogo"));
    layoutForm->addWidget(campiForm["luogo"]);
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

    campiForm["ordinedelgiorno"] = new QLineEdit();
    campiForm["url"] = new QLineEdit();

    layoutForm->addWidget(new QLabel("Ordine del giorno"));
    layoutForm->addWidget(campiForm["ordinedelgiorno"]);
    layoutForm->addWidget(new QLabel("URL"));
    layoutForm->addWidget(campiForm["url"]);
}
void VistaCreazioneAttivita::creaViaggio() {
    creaAttivitaProgrammata();

    campiForm["mezzoditrasporto"] = new QLineEdit();
    campiForm["luogopartenza"] = new QLineEdit();

    layoutForm->addWidget(new QLabel("Mezzo di trasporto"));
    layoutForm->addWidget(campiForm["mezzoditrasporto"]);
    layoutForm->addWidget(new QLabel("Luogo di partenza"));
    layoutForm->addWidget(campiForm["luogopartenza"]);

}

void VistaCreazioneAttivita::pulisciLayout(QLayout* layout) {
    if (!layout) return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* subLayout = item->layout()) {
            pulisciLayout(subLayout);
            delete subLayout;
        }
        delete item;
    }
    campiForm.clear();
}

Attivita* VistaCreazioneAttivita::creaOggettoAttivita() {

}
