#include "vistacreazioneattivita.h"

VistaCreazioneAttivita::VistaCreazioneAttivita(QWidget *parent): QWidget{parent} {
    QLabel* labelTitolo = new QLabel("Crea una nuova attività:");
    labelTitolo->setAlignment(Qt::AlignCenter);

    tipoAttivita = new QComboBox();
    tipoAttivita->setPlaceholderText("Seleziona tipo attività");
    tipoAttivita->addItem("Evento");
    tipoAttivita->addItem("Lettura");
    tipoAttivita->addItem("Promemoria");
    tipoAttivita->addItem("Riunione");
    tipoAttivita->addItem("Viaggio");

    QHBoxLayout* layoutBottoni = new QHBoxLayout;
    bottoneSalva = new QPushButton("Crea attività");
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
    layoutPrincipale->addWidget(tipoAttivita);
    layoutPrincipale->addWidget(scrollArea);
    layoutPrincipale->addLayout(layoutBottoni);

    bottoneSalva->hide();
    bottoneAnnulla->hide();

    connect(tipoAttivita, &QComboBox::activated, this, [=](int index) {
        bottoneSalva->show();
        bottoneAnnulla->show();

        QString attivitaSelezionata = tipoAttivita->itemText(index);

        if (attivitaSelezionata == "Evento") creaEvento();
        else if (attivitaSelezionata == "Lettura") creaLettura();
        else if (attivitaSelezionata == "Promemoria") creaPromemoria();
        else if (attivitaSelezionata == "Riunione") creaRiunione();
        else if (attivitaSelezionata == "Viaggio") creaViaggio();
        layoutForm->addStretch();
    });

    connect(bottoneSalva, &QPushButton::clicked, this, [this]() {
        QLineEdit* editTitolo = qobject_cast<QLineEdit*>(campiForm["titolo"]);

        if (editTitolo->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campo obbligatorio", "Il campo Titolo è obbligatorio.");
            editTitolo->setFocus();
            editTitolo->setStyleSheet("border: 1px solid red;");
            return;
        }

        Attivita *attivita = creaOggettoAttivita();
        pulisciLayout(layoutForm);
        tipoAttivita->setCurrentIndex(-1);
        bottoneSalva->hide();
        bottoneAnnulla->hide();
        emit salva(attivita);
    });

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
        tipoAttivita->setCurrentIndex(-1);
        bottoneSalva->hide();
        bottoneAnnulla->hide();
        emit annulla();
    });
}

void VistaCreazioneAttivita::creaAttivita() {
    pulisciLayout(layoutForm);

    campiForm["titolo"] = new QLineEdit();
    QLabel* labelTitolo = new QLabel("Titolo <span style='color:red;'>*</span>");
    labelTitolo->setTextFormat(Qt::RichText);
    layoutForm->addWidget(labelTitolo);
    layoutForm->addWidget(campiForm["titolo"]);

    campiForm["descrizionebreve"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Breve descrizione"));
    layoutForm->addWidget(campiForm["descrizionebreve"]);
}
void VistaCreazioneAttivita::creaAttivitaProgrammata() {
    creaAttivita();

    QDateTimeEdit* dataInizio = new QDateTimeEdit();
    dataInizio->setCalendarPopup(true);
    dataInizio->setDateTime(QDateTime::currentDateTime());
    campiForm["datainizio"] = dataInizio;
    layoutForm->addWidget(new QLabel("Data inizio"));
    layoutForm->addWidget(campiForm["datainizio"]);

    QDateTimeEdit* dataFine = new QDateTimeEdit();
    dataFine->setCalendarPopup(true);
    dataFine->setDateTime(QDateTime::currentDateTime().addSecs(3600)); // aggiunge un ora di default
    campiForm["datafine"] = dataFine;
    layoutForm->addWidget(new QLabel("Data fine"));
    layoutForm->addWidget(campiForm["datafine"]);
}
void VistaCreazioneAttivita::creaAttivitaLibera() {
    creaAttivita();

    QComboBox* stato = new QComboBox();
    stato->addItem("Non iniziata");
    stato->addItem("In corso");
    stato->addItem("Completata");
    campiForm["stato"] = stato;
    layoutForm->addWidget(new QLabel("Stato"));
    layoutForm->addWidget(campiForm["stato"]);

    QSpinBox* priorita = new QSpinBox();
    priorita->setMinimum(1);
    priorita->setMaximum(5); // da 1 a 5 con 1 bassa e 5 alta
    campiForm["priorita"] = priorita;
    layoutForm->addWidget(new QLabel("Priorità (1-5)"));
    layoutForm->addWidget(campiForm["priorita"]);
}

void VistaCreazioneAttivita::creaEvento() {
    creaAttivitaProgrammata();

    campiForm["organizzatore"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Organizzatore"));
    layoutForm->addWidget(campiForm["organizzatore"]);

    campiForm["luogo"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Luogo"));
    layoutForm->addWidget(campiForm["luogo"]);
}
void VistaCreazioneAttivita::creaLettura() {
    creaAttivitaLibera();

    campiForm["autore"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Autore"));
    layoutForm->addWidget(campiForm["autore"]);

    QSpinBox* pagine = new QSpinBox();
    pagine->setMinimum(1);
    pagine->setMaximum(9999);
    campiForm["pagine"] = pagine;
    layoutForm->addWidget(new QLabel("Numero di pagine"));
    layoutForm->addWidget(campiForm["pagine"]);

    campiForm["lingua"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Lingua"));
    layoutForm->addWidget(campiForm["lingua"]);
}
void VistaCreazioneAttivita::creaPromemoria() {
    creaAttivitaLibera();

    campiForm["nota"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Nota"));
    layoutForm->addWidget(campiForm["nota"]);
}
void VistaCreazioneAttivita::creaRiunione() {
    creaAttivitaProgrammata();

    campiForm["ordinedelgiorno"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Ordine del giorno"));
    layoutForm->addWidget(campiForm["ordinedelgiorno"]);

    campiForm["url"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("URL"));
    layoutForm->addWidget(campiForm["url"]);
}
void VistaCreazioneAttivita::creaViaggio() {
    creaAttivitaProgrammata();

    campiForm["mezzoditrasporto"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Mezzo di trasporto"));
    layoutForm->addWidget(campiForm["mezzoditrasporto"]);

    campiForm["luogopartenza"] = new QLineEdit();
    layoutForm->addWidget(new QLabel("Luogo di partenza"));
    layoutForm->addWidget(campiForm["luogopartenza"]);

}

void VistaCreazioneAttivita::pulisciLayout(QLayout* layout) {
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
    campiForm.clear();
}

Attivita* VistaCreazioneAttivita::creaOggettoAttivita(){
    if (tipoAttivita->currentText() == "Evento") {
        return new Evento(qobject_cast<QLineEdit*>(campiForm["titolo"])->text(),
                        qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text(),
                        QDateTime::currentDateTime(),
                        QDateTime::currentDateTime(),
                        qobject_cast<QDateTimeEdit*>(campiForm["datainizio"])->dateTime(),
                        qobject_cast<QDateTimeEdit*>(campiForm["datafine"])->dateTime(),
                        qobject_cast<QLineEdit*>(campiForm["organizzatore"])->text(),
                        qobject_cast<QLineEdit*>(campiForm["luogo"])->text());
    } else if (tipoAttivita->currentText() == "Lettura") {
        return new Lettura(qobject_cast<QLineEdit*>(campiForm["titolo"])->text(),
                           qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text(),
                           QDateTime::currentDateTime(),
                           QDateTime::currentDateTime(),
                           qobject_cast<QComboBox*>(campiForm["stato"])->currentText(),
                           qobject_cast<QSpinBox*>(campiForm["priorita"])->value(),
                           qobject_cast<QLineEdit*>(campiForm["autore"])->text(),
                           qobject_cast<QSpinBox*>(campiForm["pagine"])->value(),
                           qobject_cast<QLineEdit*>(campiForm["lingua"])->text());
    } else if (tipoAttivita->currentText() == "Promemoria") {
        return new Promemoria(qobject_cast<QLineEdit*>(campiForm["titolo"])->text(),
                              qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text(),
                              QDateTime::currentDateTime(),
                              QDateTime::currentDateTime(),
                              qobject_cast<QComboBox*>(campiForm["stato"])->currentText(),
                              qobject_cast<QSpinBox*>(campiForm["priorita"])->value(),
                              qobject_cast<QLineEdit*>(campiForm["nota"])->text());
    } else if (tipoAttivita->currentText() == "Riunione") {
        return new Riunione(qobject_cast<QLineEdit*>(campiForm["titolo"])->text(),
                            qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text(),
                            QDateTime::currentDateTime(),
                            QDateTime::currentDateTime(),
                            qobject_cast<QDateTimeEdit*>(campiForm["datainizio"])->dateTime(),
                            qobject_cast<QDateTimeEdit*>(campiForm["datafine"])->dateTime(),
                            qobject_cast<QLineEdit*>(campiForm["ordinedelgiorno"])->text(),
                            qobject_cast<QLineEdit*>(campiForm["url"])->text());
    } else {
        return new Viaggio(qobject_cast<QLineEdit*>(campiForm["titolo"])->text(),
                        qobject_cast<QLineEdit*>(campiForm["descrizionebreve"])->text(),
                        QDateTime::currentDateTime(),
                        QDateTime::currentDateTime(),
                        qobject_cast<QDateTimeEdit*>(campiForm["datainizio"])->dateTime(),
                        qobject_cast<QDateTimeEdit*>(campiForm["datafine"])->dateTime(),
                        qobject_cast<QLineEdit*>(campiForm["mezzoditrasporto"])->text(),
                        qobject_cast<QLineEdit*>(campiForm["luogopartenza"])->text());
    }
}

