#ifndef VISITORDETTAGLIATTIVITA_H
#define VISITORDETTAGLIATTIVITA_H

#include <attivita/VisitorInterface.h>

class VisitorDettagliAttivita: public VisitorInterface {
public:
    VisitorDettagliAttivita();

    /*virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);*/
};

#endif // VISITORDETTAGLIATTIVITA_H
