#ifndef VISITORDETTAGLI_H
#define VISITORDETTAGLI_H

#include <attivita/ConstVisitorInterface.h>

#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorDettagli : public ConstVisitorInterface {
private:
    QList<QString> listaLabel;

    void labelAttivita(const Attivita&);
    void labelAttivitaLibera(const AttivitaLibera&);
    void labelAttivitaProgrammata(const AttivitaProgrammata&);
public:
    QList<QString> getListaLabel();

    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORDETTAGLI_H
