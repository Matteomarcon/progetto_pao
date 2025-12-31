#ifndef VISTADETTAGLIATTIVITA_H
#define VISTADETTAGLIATTIVITA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "attivita/attivita.h"


class VistaDettagliAttivita : public QWidget {
    Q_OBJECT
signals:
    void modifica(Attivita*);
    void elimina(Attivita*);
private:
    Attivita* attivita;

    QLabel* labelTitolo;
    QVBoxLayout* layout;
    QList<QLabel*> listaLabel;

    QPushButton* bottoneModifica;
    QPushButton* bottoneElimina;
public:
    VistaDettagliAttivita(QWidget *parent = nullptr);
    void setAttivita(Attivita*);
};

#endif // VISTADETTAGLIATTIVITA_H
