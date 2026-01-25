#include "visitorfiltri.h"

VisitorFiltri::VisitorFiltri(const QString& tipoAttivita, const QDateTime& dataInizio, const QDateTime& dataFine): tipoAttivita(tipoAttivita),
    dataInizio(dataInizio), dataFine(dataFine) {}

bool VisitorFiltri::getMatch() {
    return match;
}

void VisitorFiltri::visit(const Evento& evento){
    (void) evento;
    match = tipoAttivita.contains("Evento") || tipoAttivita.contains("Tutte le attività");
    if (match) {
        match = (evento.getDataInizio()>=dataInizio && evento.getDataFine()<=dataFine);
    }
}

void VisitorFiltri::visit(const Lettura& lettura){
    (void) lettura;
    match = tipoAttivita.contains("Lettura") || tipoAttivita.contains("Tutte le attività");
}

void VisitorFiltri::visit(const Promemoria& promemoria){
    (void) promemoria;
    match = tipoAttivita.contains("Promemoria") || tipoAttivita.contains("Tutte le attività");
}

void VisitorFiltri::visit(const Riunione& riunione){
    (void) riunione;
    match = tipoAttivita.contains("Riunione") || tipoAttivita.contains("Tutte le attività");
    if (match) {
        match = (riunione.getDataInizio()>=dataInizio && riunione.getDataFine()<=dataFine);
    }
}

void VisitorFiltri::visit(const Viaggio& viaggio){
    (void) viaggio;
    match = tipoAttivita.contains("Viaggio") || tipoAttivita.contains("Tutte le attività");
    if (match) {
        match = (viaggio.getDataInizio()>=dataInizio && viaggio.getDataFine()<=dataFine);
    }
}
