#include "widgetfiltri.h"

widgetFiltri::widgetFiltri(QWidget *parent)
    : QWidget{parent}, visibile{true}
{
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    QHBoxLayout* layoutRicerca = new QHBoxLayout(this);
    QVBoxLayout* layoutFiltri = new QVBoxLayout(this);
    QHBoxLayout* layoutDate = new QHBoxLayout(this);

    barraRicerca = new QLineEdit();
    barraRicerca->setPlaceholderText("Cerca un attività...");

    QLabel* labelFiltri = new QLabel("Scegli data di inizio e fine");

    QPushButton* bottoneFiltri = new QPushButton("Filtra risultati");
    layoutRicerca->addWidget(barraRicerca);
    layoutRicerca->addWidget(bottoneFiltri);

    tipoAttivita = new QComboBox();
    tipoAttivita->addItem("Tutte le attività");
    tipoAttivita->addItem("Evento");
    tipoAttivita->addItem("Lettura");
    tipoAttivita->addItem("Promemoria");
    tipoAttivita->addItem("Riunione");
    tipoAttivita->addItem("Viaggio");

    QDateTimeEdit* dataInizio = new QDateTimeEdit();
    dataInizio->setDateTime(QDateTime::currentDateTime().addYears(-1));

    QDateTimeEdit* dataFine = new QDateTimeEdit();
    dataFine->setDateTime(QDateTime::currentDateTime().addYears(1));

    layoutDate->addWidget(dataInizio);
    layoutDate->addWidget(dataFine);
    layoutFiltri->addWidget(tipoAttivita);
    layoutFiltri->addWidget(labelFiltri);
    layoutFiltri->addLayout(layoutDate);
    layoutPrincipale->addLayout(layoutRicerca);
    layoutPrincipale->addLayout(layoutFiltri);

    widgets["tipoAttivita"] = tipoAttivita;
    widgets["labelFiltri"] = labelFiltri;
    widgets["dataInizio"] = dataInizio;
    widgets["dataFine"] = dataFine;

    setLayout(layoutPrincipale);
    mostraFiltri();

    connect(bottoneFiltri, &QPushButton::pressed, this, &widgetFiltri::mostraFiltri);
}

QLineEdit* widgetFiltri::getBarraRicerca() const {
    return barraRicerca;
}

QDateTimeEdit* widgetFiltri::getDataInizio() const {
    return qobject_cast<QDateTimeEdit*>(widgets["dataInizio"]);
}

QDateTimeEdit* widgetFiltri::getDataFine() const {
    return qobject_cast<QDateTimeEdit*>(widgets["dataFine"]);
}

QComboBox* widgetFiltri::getTipoAttivita() {
    return tipoAttivita;
}

void widgetFiltri::mostraFiltri() {
    if (visibile) {
        for (auto key : widgets.keys()) {
            qobject_cast<QComboBox*>(widgets["tipoAttivita"])->setCurrentIndex(0);
            qobject_cast<QDateTimeEdit*>(widgets["dataInizio"])->setDateTime(QDateTime::currentDateTime().addYears(-1));
            qobject_cast<QDateTimeEdit*>(widgets["dataFine"])->setDateTime(QDateTime::currentDateTime().addYears(1));
            widgets[key]->hide();
        }
    }
    else {
        for (auto key : widgets.keys()) {
            widgets[key]->show();
        }
    }
    visibile = !visibile;
}
