#ifndef VISITORMODIFICA_H
#define VISITORMODIFICA_H

class Evento;
class Lettura;
class Promemoria;
class Riunione;
class Viaggio;

class VisitorModifica {
public:
    virtual ~VisitorModifica() = default;

    virtual void visit(Evento&) = 0;
    virtual void visit(Lettura&) = 0;
    virtual void visit(Promemoria&) = 0;
    virtual void visit(Riunione&) = 0;
    virtual void visit(Viaggio&) = 0;
};

#endif // VISITORMODIFICA_H
