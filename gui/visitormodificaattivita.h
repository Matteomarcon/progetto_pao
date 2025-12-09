#ifndef VISITORMODIFICAATTIVITA_H
#define VISITORMODIFICAATTIVITA_H

#include <attivita/VisitorModifica.h>

class VisitorModificaAttivita: public VisitorModifica {
public:
    VisitorModificaAttivita();

    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORMODIFICAATTIVITA_H
