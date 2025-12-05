#include "vistacreazioneattivita.h"

VistaCreazioneAttivita::VistaCreazioneAttivita(QWidget *parent): QWidget{parent} {
    QLabel* labelTitolo = new QLabel("Crea una nuova attività:");
    labelTitolo->setAlignment(Qt::AlignCenter);

    tipoAttivita = new QComboBox();
    tipoAttivita->addItem("Evento");
    tipoAttivita->addItem("Lettura");
    tipoAttivita->addItem("Promemoria");
    tipoAttivita->addItem("Riunione");
    tipoAttivita->addItem("Viaggio");

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneSalva = new QPushButton("Crea Attività");
    bottoneAnnulla = new QPushButton("Annulla");

    layoutBottoni->addWidget(bottoneSalva);
    layoutBottoni->addWidget(bottoneAnnulla);

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutForm = new QVBoxLayout(this);
    layoutPrincipale->addWidget(labelTitolo);
    layoutPrincipale->addWidget(tipoAttivita);
    layoutPrincipale->addLayout(layoutForm);
    layoutPrincipale->addStretch();
    layoutPrincipale->addLayout(layoutBottoni);

    layoutForm->addWidget(new QLabel("Studio"));
}
