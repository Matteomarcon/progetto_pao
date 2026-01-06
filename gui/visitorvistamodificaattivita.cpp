#include "visitorvistamodificaattivita.h"

VisitorVistaModificaAttivita::VisitorVistaModificaAttivita(QMap<QString, QWidget*> map, QVBoxLayout *layoutForm): campiForm(map), layoutForm(layoutForm) {}

QMap<QString, QWidget*> VisitorVistaModificaAttivita::getCampiForm() {
    return campiForm;
}

void VisitorVistaModificaAttivita::modificaAttivita(const Attivita& a) {
    campiForm["titolo"] = new QLineEdit();
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
}

void VisitorVistaModificaAttivita::modificaLibera(const AttivitaLibera& al) {
    modificaAttivita(al);
}

void VisitorVistaModificaAttivita::visit(const Evento& evento) {
    modificaProgrammata(evento);
}

void VisitorVistaModificaAttivita::visit(const Lettura& lettura) {
    modificaLibera(lettura);
}

void VisitorVistaModificaAttivita::visit(const Promemoria& promemoria) {
    modificaLibera(promemoria);
}

void VisitorVistaModificaAttivita::visit(const Riunione& riunione) {
    modificaProgrammata(riunione);
}

void VisitorVistaModificaAttivita::visit(const Viaggio& viaggio) {
    modificaProgrammata(viaggio);
}
