#ifndef VISITORVISTAMODIFICAATTIVITA_H
#define VISITORVISTAMODIFICAATTIVITA_H

#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QSpinBox>

#include <attivita/VisitorInterface.h>
#include "attivita/attivita.h"
#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorVistaModificaAttivita: public VisitorInterface {
private:
    QMap<QString, QWidget*> campiForm;
    QVBoxLayout* layoutForm;
public:
    VisitorVistaModificaAttivita(QMap<QString, QWidget*>, QVBoxLayout*);

    QMap<QString, QWidget*> getCampiForm();

    void modificaAttivita(const Attivita&);
    void modificaProgrammata(const AttivitaProgrammata&);
    void modificaLibera(const AttivitaLibera&);
    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORVISTAMODIFICAATTIVITA_H
