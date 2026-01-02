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
    item = new QListWidgetItem(QIcon(":/icone/aggiungi.png"), evento.getTitolo());
}
void VisitorListaAttivita::visit(const Lettura& lettura){
    item = new QListWidgetItem(QIcon(":/icone/aggiungi.png"), lettura.getTitolo());
}
void VisitorListaAttivita::visit(const Promemoria& promemoria){
    item = new QListWidgetItem(QIcon(":/icone/aggiungi.png"), promemoria.getTitolo());
}
void VisitorListaAttivita::visit(const Riunione& riunione){
    item = new QListWidgetItem(QIcon(":/icone/aggiungi.png"), riunione.getTitolo());
}
void VisitorListaAttivita::visit(const Viaggio& viaggio){
    item = new QListWidgetItem(QIcon(":/icone/aggiungi.png"), viaggio.getTitolo());

}
