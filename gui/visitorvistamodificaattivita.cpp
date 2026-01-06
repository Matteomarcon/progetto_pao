#include "visitorvistamodificaattivita.h"

VisitorVistaModificaAttivita::VisitorVistaModificaAttivita(QMap<QString, QWidget*> map, QVBoxLayout *layoutForm): campiForm(map), layoutForm(layoutForm) {}

QMap<QString, QWidget*> VisitorVistaModificaAttivita::getCampiForm() {
    return campiForm;
}

void VisitorVistaModificaAttivita::modificaAttivita(const Attivita& a) {
    campiForm["titolo"] = new QLineEdit(a.getTitolo());
    QLabel* labelTitolo = new QLabel("Titolo <span style='color:red;'>*</span>");
    labelTitolo->setTextFormat(Qt::RichText);
    layoutForm->addWidget(labelTitolo);
    layoutForm->addWidget(campiForm["titolo"]);

    campiForm["descrizionebreve"] = new QLineEdit(a.getDescrizioneBreve());
    layoutForm->addWidget(new QLabel("Breve descrizione"));
    layoutForm->addWidget(campiForm["descrizionebreve"]);
}

void VisitorVistaModificaAttivita::modificaProgrammata(const AttivitaProgrammata& ap) {
    modificaAttivita(ap);

    QDateTimeEdit* dataInizio = new QDateTimeEdit(ap.getDataInizio());
    dataInizio->setCalendarPopup(true);
    campiForm["datainizio"] = dataInizio;
    layoutForm->addWidget(new QLabel("Data inizio"));
    layoutForm->addWidget(campiForm["datainizio"]);

    QDateTimeEdit* dataFine = new QDateTimeEdit(ap.getDataFine());
    dataFine->setCalendarPopup(true);
    campiForm["datafine"] = dataFine;
    layoutForm->addWidget(new QLabel("Data fine"));
    layoutForm->addWidget(campiForm["datafine"]);
}

void VisitorVistaModificaAttivita::modificaLibera(const AttivitaLibera& al) {
    modificaAttivita(al);

    QComboBox* stato = new QComboBox();
    stato->addItem("Non iniziata");
    stato->addItem("In corso");
    stato->addItem("Completata");
    stato->setCurrentText(al.getStato());
    campiForm["stato"] = stato;
    layoutForm->addWidget(new QLabel("Stato"));
    layoutForm->addWidget(campiForm["stato"]);

    QSpinBox* priorita = new QSpinBox();
    priorita->setMinimum(1);
    priorita->setMaximum(5); // da 1 a 5 con 1 bassa e 5 alta
    priorita->setValue(al.getPriorita());
    campiForm["priorita"] = priorita;
    layoutForm->addWidget(new QLabel("Priorità (1-5)"));
    layoutForm->addWidget(campiForm["priorita"]);
}

void VisitorVistaModificaAttivita::visit(const Evento& evento) {
    modificaProgrammata(evento);

    campiForm["organizzatore"] = new QLineEdit(evento.getOrganizzatore());
    layoutForm->addWidget(new QLabel("Organizzatore"));
    layoutForm->addWidget(campiForm["organizzatore"]);

    campiForm["luogo"] = new QLineEdit(evento.getLuogo());
    layoutForm->addWidget(new QLabel("Luogo"));
    layoutForm->addWidget(campiForm["luogo"]);
}

void VisitorVistaModificaAttivita::visit(const Lettura& lettura) {
    modificaLibera(lettura);

    campiForm["autore"] = new QLineEdit(lettura.getAutore());
    layoutForm->addWidget(new QLabel("Autore"));
    layoutForm->addWidget(campiForm["autore"]);

    QSpinBox* pagine = new QSpinBox();
    pagine->setMinimum(1);
    pagine->setMaximum(9999);
    pagine->setValue(lettura.getPagine());
    campiForm["pagine"] = pagine;
    layoutForm->addWidget(new QLabel("Numero di pagine"));
    layoutForm->addWidget(campiForm["pagine"]);

    campiForm["lingua"] = new QLineEdit(lettura.getLingua());
    layoutForm->addWidget(new QLabel("Lingua"));
    layoutForm->addWidget(campiForm["lingua"]);
}

void VisitorVistaModificaAttivita::visit(const Promemoria& promemoria) {
    modificaLibera(promemoria);

    campiForm["nota"] = new QLineEdit(promemoria.getNota());
    layoutForm->addWidget(new QLabel("Nota"));
    layoutForm->addWidget(campiForm["nota"]);
}

void VisitorVistaModificaAttivita::visit(const Riunione& riunione) {
    modificaProgrammata(riunione);

    campiForm["ordinedelgiorno"] = new QLineEdit(riunione.getOrdineDelGiorno());
    layoutForm->addWidget(new QLabel("Ordine del giorno"));
    layoutForm->addWidget(campiForm["ordinedelgiorno"]);

    campiForm["url"] = new QLineEdit(riunione.getUrl());
    layoutForm->addWidget(new QLabel("URL"));
    layoutForm->addWidget(campiForm["url"]);
}

void VisitorVistaModificaAttivita::visit(const Viaggio& viaggio) {
    modificaProgrammata(viaggio);

    campiForm["mezzoditrasporto"] = new QLineEdit(viaggio.getMezzoDiTrasporto());
    layoutForm->addWidget(new QLabel("Mezzo di trasporto"));
    layoutForm->addWidget(campiForm["mezzoditrasporto"]);

    campiForm["luogopartenza"] = new QLineEdit(viaggio.getLuogoPartenza());
    layoutForm->addWidget(new QLabel("Luogo di partenza"));
    layoutForm->addWidget(campiForm["luogopartenza"]);
}
