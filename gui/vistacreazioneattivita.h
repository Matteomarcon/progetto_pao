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
#include <QScrollArea>
#include <QMessageBox>
#include <QShortcut>

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
    QVBoxLayout* layoutForm;
    QPushButton* bottoneSalva;
    QPushButton* bottoneAnnulla;
    QShortcut* shortcutSalva;
    QShortcut* shortcutAnnulla;

    void creaAttivita();
    void creaAttivitaProgrammata();
    void creaAttivitaLibera();
public:
    VistaCreazioneAttivita(QWidget* parent = nullptr);

    void creaEvento();
    void creaLettura();
    void creaPromemoria();
    void creaRiunione();
    void creaViaggio();
    void pulisciLayout(QLayout*);
    Attivita* creaOggettoAttivita();
};

#endif // VISTACREAZIONEATTIVITA_H
