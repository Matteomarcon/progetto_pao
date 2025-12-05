#ifndef VISTACREAZIONEATTIVITA_H
#define VISTACREAZIONEATTIVITA_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "attivita/attivita.h"

class VistaCreazioneAttivita : public QWidget {
    Q_OBJECT
private:
    QComboBox* tipoAttivita;
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
signals:
    void annullaCreazione();
    void salvaCreazione(Attivita*);
};

/*Potrebbe servire altro:

private:
    QString imagePath;
    QMap<QString, QWidget*> widgets;

public:
    void clearLayout(QLayout*);
    Component* applyChanges();
};*/


#endif // VISTACREAZIONEATTIVITA_H
