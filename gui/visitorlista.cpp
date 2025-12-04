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
    item = new QListWidgetItem(QIcon("list_img/book.jpeg"), evento.getTitolo());
}
void VisitorLista::visit(const Lettura& lettura){
    item = new QListWidgetItem(QIcon("list_img/book.jpeg"), lettura.getTitolo());
}
void VisitorLista::visit(const Promemoria& promemoria){
    item = new QListWidgetItem(QIcon("list_img/movie.png"), promemoria.getTitolo());
}
void VisitorLista::visit(const Riunione& riunione){
    item = new QListWidgetItem(QIcon("list_img/album.jpeg"), riunione.getTitolo());
}
void VisitorLista::visit(const Viaggio& viaggio){
    item = new QListWidgetItem(QIcon("list_img/comic.png"), viaggio.getTitolo());

}
