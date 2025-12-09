#ifndef VISTAMODIFICAATTIVITA_H
#define VISTAMODIFICAATTIVITA_H

#include <QWidget>
#include <QPushButton>

#include "attivita/attivita.h"

class VistaModificaAttivita : public QWidget {
    Q_OBJECT
signals:
    void annulla();
    void salva(Attivita*);
private:
    Attivita* attivita;
    QPushButton* bottoneModifica;
    QPushButton* bottoneElimina;
    void salvaModifica();
public:
    VistaModificaAttivita(QWidget *parent = nullptr);
    void setAttivita(Attivita*);
    void pulisciLayout(QLayout*);
};

#endif // VISTAMODIFICAATTIVITA_H
