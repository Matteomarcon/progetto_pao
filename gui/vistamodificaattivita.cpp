#include "vistamodificaattivita.h"
#include <QVBoxLayout>

VistaModificaAttivita::VistaModificaAttivita(QWidget *parent): QWidget{parent} {
    labelTitolo = new QLabel();
    labelTitolo->setAlignment(Qt::AlignCenter);

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneSalva = new QPushButton("Salva modifica");
    bottoneAnnulla = new QPushButton("Annulla");

    layoutBottoni->addWidget(bottoneSalva);
    layoutBottoni->addWidget(bottoneAnnulla);

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    QWidget* widgetForm = new QWidget(this);
    layoutForm = new QVBoxLayout(widgetForm);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(widgetForm);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layoutPrincipale->addWidget(labelTitolo);
    layoutPrincipale->addWidget(scrollArea);
    layoutPrincipale->addLayout(layoutBottoni);

    connect(bottoneAnnulla, &QPushButton::clicked, this, [this]() {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Conferma annullamento");
        msgBox.setText("Sei sicuro di voler annullare?\nLe modifiche andranno perse.");

        QPushButton* btnSi =
            msgBox.addButton("Conferma", QMessageBox::YesRole);
        QPushButton* btnNo =
            msgBox.addButton("Torna indietro", QMessageBox::NoRole);

        msgBox.setDefaultButton(btnNo);
        msgBox.exec();

        if (msgBox.clickedButton() != btnSi)
            return;

        pulisciLayout(layoutForm);
        emit annulla(attivita);
    });

}

void VistaModificaAttivita::setAttivita(Attivita* a) {
    if (!a) return;
    attivita = a;

    labelTitolo->setText("Stai modificando l'attività: " + attivita->getTitolo());
}

void VistaModificaAttivita::pulisciLayout(QLayout* layout) {
    if (!layout) return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* subLayout = item->layout()) {
            pulisciLayout(subLayout);
            delete subLayout;
        }
        delete item;
    }
}
