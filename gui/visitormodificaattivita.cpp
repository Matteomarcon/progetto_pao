#include "visitormodificaattivita.h"

VisitorModificaAttivita::VisitorModificaAttivita(const QMap<QString, QWidget*>& campiForm): campiForm(campiForm) {}

void VisitorModificaAttivita::modificaAttivita(Attivita& a) {
    a.setTitolo(qobject_cast<QLineEdit*>(campiForm["titolo"])->text());
    a.setDescrizioneBreve(qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text());
    a.setUltimaModifica(QDateTime::currentDateTime());
}

void VisitorModificaAttivita::modificaProgrammata(AttivitaProgrammata& ap) {
    modificaAttivita(ap);

    ap.setDataInizio(qobject_cast<QDateTimeEdit*>(campiForm["datainizio"])->dateTime());
    ap.setDataFine(qobject_cast<QDateTimeEdit*>(campiForm["datafine"])->dateTime());
}

void VisitorModificaAttivita::modificaLibera(AttivitaLibera& al) {
    modificaAttivita(al);

    al.setStato(qobject_cast<QComboBox*>(campiForm["stato"])->currentText());
    al.setPriorita(qobject_cast<QSpinBox*>(campiForm["priorita"])->value());
}

void VisitorModificaAttivita::visit(Evento& evento) {
    modificaProgrammata(evento);

    evento.setOrganizzatore(qobject_cast<QLineEdit*>(campiForm["organizzatore"])->text());
    evento.setLuogo(qobject_cast<QLineEdit*>(campiForm["luogo"])->text());
}

void VisitorModificaAttivita::visit(Lettura& lettura) {
    modificaLibera(lettura);

    lettura.setAutore(qobject_cast<QLineEdit*>(campiForm["autore"])->text());
    lettura.setPagine(qobject_cast<QSpinBox*>(campiForm["pagine"])->value());
    lettura.setLingua(qobject_cast<QLineEdit*>(campiForm["lingua"])->text());
}

void VisitorModificaAttivita::visit(Promemoria& promemoria) {
    modificaLibera(promemoria);

    promemoria.setNota(qobject_cast<QLineEdit*>(campiForm["nota"])->text());
}

void VisitorModificaAttivita::visit(Riunione& riunione) {
    modificaProgrammata(riunione);

    riunione.setOrdineDelGiorno(qobject_cast<QLineEdit*>(campiForm["ordinedelgiorno"])->text());
    riunione.setUrl(qobject_cast<QLineEdit*>(campiForm["url"])->text());
}

void VisitorModificaAttivita::visit(Viaggio& viaggio) {
    modificaProgrammata(viaggio);

    viaggio.setMezzoDiTrasporto(qobject_cast<QLineEdit*>(campiForm["mezzoditrasporto"])->text());
    viaggio.setLuogoPartenza(qobject_cast<QLineEdit*>(campiForm["luogopartenza"])->text());
}
