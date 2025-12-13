#ifndef VISTACREAZIONEATTIVITA_H
#define VISTACREAZIONEATTIVITA_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateTimeEdit>

#include "attivita/attivita.h"
#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VistaCreazioneAttivita : public QWidget {
    Q_OBJECT
signals:
    void annulla();
    void salva(Attivita*);
private:
    QComboBox* tipoAttivita;
    QMap<QString, QWidget*> campiForm;
    QVBoxLayout* layoutForm = nullptr;
    QPushButton* bottoneSalva;
    QPushButton* bottoneAnnulla;
public:
    VistaCreazioneAttivita(QWidget *parent = nullptr);
    void creaAttivita();
    void creaAttivitaProgrammata();
    void creaAttivitaLibera();
    void creaEvento();
    void creaLettura();
    void creaPromemoria();
    void creaRiunione();
    void creaViaggio();
    void pulisciLayout(QLayout*);
    Attivita* creaOggettoAttivita();
};

#endif // VISTACREAZIONEATTIVITA_H
