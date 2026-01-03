#include "visitorlabel.h"

QList<QString> VisitorLabel::getListaLabel() {
    return listaLabel;
}

void VisitorLabel::labelAttivita(const Attivita& a) {
    listaLabel.append("Titolo:\n" + a.getTitolo());
    listaLabel.append("Descrizione breve:\n" + a.getDescrizioneBreve());
    listaLabel.append("Data creazione:\n" + a.getDataCreazione().toString());
    listaLabel.append("Data ultima modifica:\n" + a.getUltimaModifica().toString());
}

void VisitorLabel::labelAttivitaLibera(const AttivitaLibera& al) {
    labelAttivita(al);
    listaLabel.append("Priorità:\n" + QString::number(al.getPriorita()));
    listaLabel.append(al.getStato());
}

void VisitorLabel::labelAttivitaProgrammata(const AttivitaProgrammata& ap) {
    labelAttivita(ap);
    listaLabel.append("Data inizio:\n" + ap.getDataInizio().toString());
    listaLabel.append("Data fine:\n" + ap.getDataFine().toString());
}

void VisitorLabel::visit(const Evento& evento) {
    labelAttivitaProgrammata(evento);
    listaLabel.append("Luogo:\n" + evento.getLuogo());
    listaLabel.append("Organizzatore:\n" + evento.getOrganizzatore());
}

void VisitorLabel::visit(const Lettura& lettura) {
    labelAttivitaLibera(lettura);
    listaLabel.append("Autore:\n" + lettura.getAutore());
    listaLabel.append("Lingua:\n" + lettura.getLingua());
    listaLabel.append("Pagine:\n" + QString::number(lettura.getPagine()));
}

void VisitorLabel::visit(const Promemoria& promemoria) {
    labelAttivitaLibera(promemoria);
    listaLabel.append("Nota:\n" + promemoria.getNota());
}

void VisitorLabel::visit(const Riunione& riunione) {
    labelAttivitaProgrammata(riunione);
    listaLabel.append("Ordine del giorno:\n" + riunione.getOrdineDelGiorno());
    listaLabel.append("Url:\n" + riunione.getUrl());
}

void VisitorLabel::visit(const Viaggio& viaggio){
    labelAttivitaProgrammata(viaggio);
    listaLabel.append("Luogo di partenza:\n" + viaggio.getLuogoPartenza());
    listaLabel.append("Mezzo di trasporto:\n" + viaggio.getMezzoDiTrasporto());
}
