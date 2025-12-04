#include "vistalistaattivita.h"

VistaListaAttivita::VistaListaAttivita(QList<Attivita*> listaAttivita, QWidget *parent): QWidget{parent}, listaAttivita(listaAttivita) {
    widgetLista = new QListWidget(this);
    widgetLista->setUniformItemSizes(true);
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
    widgetLista->setCursor(Qt::PointingHandCursor);

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addWidget(widgetLista);
    setLayout(layoutPrincipale);

    /* chiamata a metodo refresh per creare la lista sui dati correnti
    refresh(data);

    connect(widgetList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        if (itemMap[item]) emit itemSelected(itemMap[item]);
        else qDebug() << "Item not in map or null!";
    });*/
}
