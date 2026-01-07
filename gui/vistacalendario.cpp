#include "vistacalendario.h"
#include "attivita/attivitaprogrammata.h"


vistacalendario::vistacalendario(QList<Attivita*> listaAttivita, QWidget *parent)
    : listaAttivita(listaAttivita) ,QWidget{parent}
{
    QVBoxLayout* layoutPrincipale = new QVBoxLayout(this);
    QLabel* labelTitolo = new QLabel("Calendario delle attività programmate");
    labelDescrizione = new QLabel();
    labelTitolo->setAlignment(Qt::AlignCenter);

    calendario = new QCalendarWidget(this);

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneChiudi = new QPushButton("Chiudi calendario");

    layoutBottoni->addWidget(bottoneChiudi);

    layoutPrincipale->addWidget(labelTitolo);
    layoutPrincipale->addWidget(calendario);
    layoutPrincipale->addWidget(labelDescrizione);
    layoutPrincipale->addStretch();
    layoutPrincipale->addLayout(layoutBottoni);

    connect(bottoneChiudi, &QPushButton::clicked, this, [this]() {
        emit chiudi();
    });
    connect(calendario, &QCalendarWidget::clicked, this, &vistacalendario::onDataSelezionata);
}

void vistacalendario::aggiornaCalendario(const QList<Attivita*>& nuovaLista) {
    calendario->setDateTextFormat(QDate(), QTextCharFormat());

    listaAttivita = nuovaLista;

    for (auto attivita : listaAttivita) {
        auto ap = dynamic_cast<AttivitaProgrammata*>(attivita);
        if (ap) {
            QDate start = ap->getDataInizio().date();
            QDate end   = ap->getDataFine().date();

            QDate d = start;
            while (d <= end) {
                giorniConAttivita[d]++;
                d = d.addDays(1);
            }
        }
    }
    for (auto it = giorniConAttivita.begin(); it != giorniConAttivita.end(); ++it) {
        QTextCharFormat format;

        format.setBackground(Qt::yellow);
        format.setForeground(Qt::black);
        format.setFontWeight(QFont::Bold);

        format.setToolTip(QString("%1 attività").arg(it.value()));

        calendario->setDateTextFormat(it.key(), format);
    }
}

void vistacalendario::onDataSelezionata(const QDate &date) {
    QLocale it(QLocale::Italian, QLocale::Italy);
    labelDescrizione->setText("Nel giorno " + it.toString(date, QLocale::LongFormat) + " hai programmato " + QString::number(giorniConAttivita[date]) + " attività");
}
