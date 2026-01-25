#ifndef VISITORMODIFICAATTIVITA_H
#define VISITORMODIFICAATTIVITA_H

#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QDateTimeEdit>

#include <attivita/VisitorInterface.h>
#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorModificaAttivita: public VisitorInterface {
private:
    QMap<QString, QWidget*> campiForm;

    void modificaAttivita(Attivita&);
    void modificaProgrammata(AttivitaProgrammata&);
    void modificaLibera(AttivitaLibera&);
public:
    VisitorModificaAttivita(const QMap<QString, QWidget*>&);

    virtual void visit(Evento&);
    virtual void visit(Lettura&);
    virtual void visit(Promemoria&);
    virtual void visit(Riunione&);
    virtual void visit(Viaggio&);
};

#endif // VISITORMODIFICAATTIVITA_H
