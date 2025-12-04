#include "visitorlista.h"

QListWidgetItem* VisitorLista::getItem(){
    if (!item) return nullptr;

    item->setSizeHint(QSize(250, 60));
    QFont font;
    font.setBold(true);
    item->setFont(font);
    return item;
}

void VisitorLista::visit(const Evento& evento){
    item = new QListWidgetItem(QIcon("../../icone/aggiungi.png"), evento.getTitolo());
}
void VisitorLista::visit(const Lettura& lettura){
    item = new QListWidgetItem(QIcon("../../icone/aggiungi.png"), lettura.getTitolo());
}
void VisitorLista::visit(const Promemoria& promemoria){
    item = new QListWidgetItem(QIcon("../../icone/aggiungi.png"), promemoria.getTitolo());
}
void VisitorLista::visit(const Riunione& riunione){
    item = new QListWidgetItem(QIcon("../../icone/aggiungi.png"), riunione.getTitolo());
}
void VisitorLista::visit(const Viaggio& viaggio){
    item = new QListWidgetItem(QIcon("../../icone/aggiungi.png"), viaggio.getTitolo());

}
