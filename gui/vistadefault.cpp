#include "vistadefault.h"

VistaDefault::VistaDefault(QWidget *parent): QWidget{parent}{
    QLabel* labelDefault = new QLabel("Gestore Attività Personali\n\nCrea, salva e modifica le tue attività\nSeleziona le attività nella lista e visualizzane i dettagli");
    labelDefault->setAlignment(Qt::AlignCenter);
    labelDefault->setStyleSheet("font-size: 18px;");

    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->addWidget(labelDefault);
}
