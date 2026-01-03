#include "vistadettagliattivita.h"
#include "gui/visitorlabel.h"

VistaDettagliAttivita::VistaDettagliAttivita(QWidget *parent) : QWidget{parent} {
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    labelTitolo = new QLabel();
    labelTitolo->setAlignment(Qt::AlignCenter);
    layout = new QVBoxLayout();

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneElimina = new QPushButton("Elimina attività");
    bottoneModifica = new QPushButton("Modifica attività");
    bottoneChiudi = new QPushButton("Chiudi dettaglio");

    layoutBottoni->addWidget(bottoneElimina);
    layoutBottoni->addWidget(bottoneModifica);
    layoutBottoni->addWidget(bottoneChiudi);

    layoutPrincipale->addWidget(labelTitolo);
    layoutPrincipale->addLayout(layout);
    layoutPrincipale->addStretch();
    layoutPrincipale->addLayout(layoutBottoni);

    connect(bottoneChiudi, &QPushButton::clicked, this, [this]() {
        emit chiudi();
    });
    connect(bottoneElimina, &QPushButton::clicked, this, [this]() {
        emit elimina(attivita);
    });
}

void VistaDettagliAttivita::setAttivita(Attivita* a) {
    if (!a) return;
    attivita = a;

    labelTitolo->setText("Dettaglio dell'attività: " + attivita->getTitolo());

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

