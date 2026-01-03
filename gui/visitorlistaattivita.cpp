#include "visitorlistaattivita.h"

QListWidgetItem* VisitorListaAttivita::getItem(){
    if (!item) return nullptr;

    item->setSizeHint(QSize(250, 60));
    QFont font;
    font.setBold(true);
    item->setFont(font);
    return item;
}

void VisitorListaAttivita::visit(const Evento& evento){
    item = new QListWidgetItem(QIcon(":/icone/evento.png"), "Evento\n" + evento.getTitolo());
}
void VisitorListaAttivita::visit(const Lettura& lettura){
    item = new QListWidgetItem(QIcon(":/icone/lettura.png"), "Lettura\n" + lettura.getTitolo());
}
void VisitorListaAttivita::visit(const Promemoria& promemoria){
    item = new QListWidgetItem(QIcon(":/icone/promemoria.png"), "Promemoria\n" + promemoria.getTitolo());
}
void VisitorListaAttivita::visit(const Riunione& riunione){
    item = new QListWidgetItem(QIcon(":/icone/riunione.png"), "Riunione\n" + riunione.getTitolo());
}
void VisitorListaAttivita::visit(const Viaggio& viaggio){
    item = new QListWidgetItem(QIcon(":/icone/viaggio.png"), "Viaggio\n" + viaggio.getTitolo());

}
