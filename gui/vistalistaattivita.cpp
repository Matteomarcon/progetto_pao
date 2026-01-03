#include "vistalistaattivita.h"

VistaListaAttivita::VistaListaAttivita(QList<Attivita*> listaAttivita, QWidget *parent): QWidget{parent}, listaAttivita(listaAttivita) {
    widgetLista = new QListWidget(this);
    widgetLista->setIconSize(QSize(48, 48));

    aggiornaLista(listaAttivita);

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addWidget(widgetLista);
    setLayout(layoutPrincipale);

    connect(widgetLista, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        if (mappaItemAttivita[item]) emit itemSelezionato(mappaItemAttivita[item]);
    });
}

void VistaListaAttivita::aggiornaLista(const QList<Attivita*>& listaAggiornata) {
    widgetLista->clear();
    mappaItemAttivita.clear();

    listaAttivita = listaAggiornata;

    for (auto attivita : listaAttivita) {
        VisitorListaAttivita visitor;
        attivita->accept(visitor);
        QListWidgetItem* item = visitor.getItem();
        widgetLista->addItem(item);
        mappaItemAttivita[item] = attivita;
    }
}

void VistaListaAttivita::deseleziona() {
    widgetLista->clearSelection();
    widgetLista->clearFocus();
    widgetLista->setCurrentItem(nullptr);
}
