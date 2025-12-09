#ifndef VISTAMODIFICAATTIVITA_H
#define VISTAMODIFICAATTIVITA_H

#include <QWidget>
#include <QPushButton>

#include "attivita/attivita.h"

class VistaModificaAttivita : public QWidget {
    Q_OBJECT
signals:
    void annullaModifica();
    void salvaModifica(Attivita*);
private:
    Attivita* attivita;
    QPushButton* bottoneModifica;
    QPushButton* bottoneElimina;
public:
    VistaModificaAttivita(QWidget *parent = nullptr);
    void setAttivita(Attivita*);
    void setEvento(Evento*);
    void setLettura(Lettura*);
    void setPromemoria(Promemoria*);
    void setRiunione(Riunione*);
    void setViaggio(Viaggio*);
};

#endif // VISTAMODIFICAATTIVITA_H
