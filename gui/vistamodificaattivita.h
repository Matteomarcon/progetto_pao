#ifndef VISTAMODIFICAATTIVITA_H
#define VISTAMODIFICAATTIVITA_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMessageBox>

#include "attivita/attivita.h"

#include "visitorvistamodificaattivita.h"

class VistaModificaAttivita : public QWidget {
    Q_OBJECT
signals:
    void annulla(Attivita*);
    void salva(Attivita*);
private:
    Attivita* attivita;
    QLabel* labelTitolo;

    QVBoxLayout* layoutForm;
    QMap<QString, QWidget*> campiForm;
    QPushButton* bottoneSalva;
    QPushButton* bottoneAnnulla;

    void salvaModifica();
public:
    VistaModificaAttivita(QWidget *parent = nullptr);
    void setAttivita(Attivita*);
    void pulisciLayout(QLayout*);
};

#endif // VISTAMODIFICAATTIVITA_H
