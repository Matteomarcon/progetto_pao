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
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Sei sicuro di voler annullare?\nLe modifiche andranno perse.");

        QPushButton* btnSi = msgBox.addButton("Conferma", QMessageBox::YesRole);
        QPushButton* btnNo = msgBox.addButton("Torna indietro", QMessageBox::NoRole);

        msgBox.setDefaultButton(btnNo);
        msgBox.exec();

        if (msgBox.clickedButton() != btnSi) return;

        pulisciLayout(layoutForm);
        emit annulla(attivita);
    });

    connect(bottoneSalva, &QPushButton::clicked, this, [this]() {
        QLineEdit* editTitolo = qobject_cast<QLineEdit*>(campiForm["titolo"]);

        if (editTitolo->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campo obbligatorio", "Il campo Titolo è obbligatorio.");
            editTitolo->setFocus();
            editTitolo->setStyleSheet("border: 1px solid red;");
            return;
        }

        salvaModifica();
        emit salva(attivita);
    });

}

void VistaModificaAttivita::setAttivita(Attivita* a) {
    if (!a) return;
    attivita = a;

    labelTitolo->setText("Stai modificando l'attività: " + attivita->getTitolo());

    pulisciLayout(layoutForm);

    VisitorVistaModificaAttivita visitor(campiForm, layoutForm);
    attivita->accept(visitor);
    campiForm = visitor.getCampiForm();
    layoutForm->addStretch();
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

void VistaModificaAttivita::salvaModifica() {
    if (!attivita) return;

    VisitorModificaAttivita visitor(campiForm);
    attivita->accept(visitor);
}
