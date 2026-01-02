#include "vistalistaattivita.h"

VistaListaAttivita::VistaListaAttivita(QList<Attivita*> listaAttivita, QWidget *parent): QWidget{parent}, listaAttivita(listaAttivita) {
    widgetLista = new QListWidget(this);
    /*widgetLista->setUniformItemSizes(true);
    widgetLista->setIconSize(QSize(50, 50));
    widgetLista->setStyleSheet(R"(
        QListWidget::item {
            background-color: white;
            padding: 5px;
            outline: none;
        }
        QListWidget::item:selected {
            background-color: #7099ba;
            outline: none;
        }
        QListWidget::item:hover {
            background-color: #c1c6c9;
            outline: none;
        }
        QListWidget::item:focus {
            outline: none;
        }
    )");
    widgetLista->setCursor(Qt::PointingHandCursor);*/

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
