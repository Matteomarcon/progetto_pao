#include "visitorlabel.h"

QList<QString> VisitorLabel::getListaLabel() {
    return listaLabel;
}

void VisitorLabel::labelAttivita(const Attivita& a) {
    listaLabel.append("Titolo: " + a.getTitolo());
}
void VisitorLabel::labelAttivitaLibera(const AttivitaLibera& al) {
    labelAttivita(al);

}
void VisitorLabel::labelAttivitaProgrammata(const AttivitaProgrammata& ap) {
    labelAttivita(ap);

}
void VisitorLabel::visit(const Evento& evento) {
    labelAttivitaProgrammata(evento);
}
void VisitorLabel::visit(const Lettura& lettura) {
    labelAttivitaLibera(lettura);
}
void VisitorLabel::visit(const Promemoria& promemoria) {
    labelAttivitaLibera(promemoria);
}
void VisitorLabel::visit(const Riunione& riunione) {
    labelAttivitaProgrammata(riunione);
}
void VisitorLabel::visit(const Viaggio& viaggio){
    labelAttivitaProgrammata(viaggio);
}
