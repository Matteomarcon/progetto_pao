#include "visitormatch.h"

VisitorMatch::VisitorMatch(QString tipoAttivita, QDateTime dataInizio, QDateTime dataFine): tipoAttivita(tipoAttivita),
    dataInizio(dataInizio), dataFine(dataFine) {}

bool VisitorMatch::getMatch() {
    return match;
}

//CONTROLLI DATA INIZIO DATA FINE

void VisitorMatch::visit(const Evento& evento){
    (void) evento;
    match = tipoAttivita.contains("evento");
    if (match) {
        match = (evento.getDataInizio()>=dataInizio && evento.getDataFine()<=dataFine);
    }
}
void VisitorMatch::visit(const Lettura& lettura){
    (void) lettura;
    match = tipoAttivita.contains("lettura");
}
void VisitorMatch::visit(const Promemoria& promemoria){
    (void) promemoria;
    match = tipoAttivita.contains("promemoria");
}
void VisitorMatch::visit(const Riunione& riunione){
    (void) riunione;
    match = tipoAttivita.contains("riunione");
    if (match) {
        match = (riunione.getDataInizio()>=dataInizio && riunione.getDataFine()<=dataFine);
    }
}
void VisitorMatch::visit(const Viaggio& viaggio){
    (void) viaggio;
    match = tipoAttivita.contains("viaggio");
    if (match) {
        match = (viaggio.getDataInizio()>=dataInizio && viaggio.getDataFine()<=dataFine);
    }
}
