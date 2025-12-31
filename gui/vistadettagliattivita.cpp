#include "vistadettagliattivita.h"
#include "gui/visitorlabel.h"

VistaDettagliAttivita::VistaDettagliAttivita(QWidget *parent) : QWidget{parent} {


}

void VistaDettagliAttivita::setAttivita(Attivita* a) {
    if (!a) return;
    attivita = a;

    labelTitolo->setText(attivita->getTitolo());

    for (QLabel *label : listaLabel) {
        layout->removeWidget(label);
        label->deleteLater();
    }
    listaLabel.clear();

    VisitorLabel visitor;
    attivita->accept(visitor);
    QList<QString> specificAttr = visitor.getListaLabel();

    for (auto attr : specificAttr) {
        QLabel *lbl = new QLabel(attr);
        layout->addWidget(lbl);
        listaLabel.append(lbl);
    }
}
