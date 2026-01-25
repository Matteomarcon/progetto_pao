#include "vistadettagliattivita.h"
#include "gui/visitordettagli.h"

VistaDettagliAttivita::VistaDettagliAttivita(QWidget *parent) : QWidget{parent} {
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    labelTitolo = new QLabel();
    labelTitolo->setAlignment(Qt::AlignCenter);
    layout = new QVBoxLayout();

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneElimina = new QPushButton("Elimina attività");
    bottoneModifica = new QPushButton("Modifica attività");
    bottoneChiudi = new QPushButton("Chiudi dettaglio");

    bottoneElimina->setToolTip("Elimina attività (Canc)");
    bottoneModifica->setToolTip("Modifica attività (Ctrl+M)");
    bottoneChiudi->setToolTip("Chiudi dettaglio (Esc)");

    QShortcut* shortcutElimina = new QShortcut(QKeySequence(Qt::Key_Delete), this);
    connect(shortcutElimina, &QShortcut::activated, bottoneElimina, &QPushButton::click);
    QShortcut* shortcutModifica = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_M), this);
    connect(shortcutModifica, &QShortcut::activated, bottoneModifica, &QPushButton::click);
    QShortcut* shortcutAnnulla = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(shortcutAnnulla, &QShortcut::activated, bottoneChiudi, &QPushButton::click);

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
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Conferma eliminazione");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Sei sicuro di voler eliminare questa attività?\nL'attività andrà persa.");

        QPushButton* btnSi = msgBox.addButton("Conferma", QMessageBox::YesRole);
        QPushButton* btnNo = msgBox.addButton("Torna indietro", QMessageBox::NoRole);

        msgBox.setDefaultButton(btnNo);
        msgBox.exec();

        if (msgBox.clickedButton() != btnSi) return;

        emit elimina(attivita);
    });
    connect(bottoneModifica, &QPushButton::clicked, this, [this]() {
        emit modifica(attivita);
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

    VisitorDettagli visitor;
    attivita->accept(visitor);
    QList<QString> specificAttr = visitor.getListaLabel();

    for (auto attr : specificAttr) {
        QLabel *lbl = new QLabel(attr);
        layout->addWidget(lbl);
        listaLabel.append(lbl);
    }
}

