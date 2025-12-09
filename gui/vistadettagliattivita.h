#ifndef VISTADETTAGLIATTIVITA_H
#define VISTADETTAGLIATTIVITA_H

#include <QWidget>
#include <QPushButton>

#include "attivita/attivita.h"

class VistaDettagliAttivita : public QWidget {
    Q_OBJECT
signals:
    void modifica(Attivita*);
    void elimina(Attivita*);
private:
    Attivita* attivita;
    QPushButton* bottoneModifica;
    QPushButton* bottoneElimina;
public:
    VistaDettagliAttivita(QWidget *parent = nullptr);
    void setAttivita(Attivita*);
};

/*QLabel* titleLabel;
QLabel* imageLabel;
QVBoxLayout* typeSpecificLayout;
QList<QLabel*> typeLabel;

public:
void updateBookButton();
};*/

#endif // VISTADETTAGLIATTIVITA_H
