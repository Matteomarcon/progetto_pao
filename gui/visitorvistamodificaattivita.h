#ifndef VISITORVISTAMODIFICAATTIVITA_H
#define VISITORVISTAMODIFICAATTIVITA_H

#include <attivita/VisitorInterface.h>

class VisitorVistaModificaAttivita: public VisitorInterface {
public:
    VisitorVistaModificaAttivita();

    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORVISTAMODIFICAATTIVITA_H
