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

    virtual void visit(const Evento&) = 0;
    virtual void visit(const Lettura&) = 0;
    virtual void visit(const Promemoria&) = 0;
    virtual void visit(const Riunione&) = 0;
    virtual void visit(const Viaggio&) = 0;
};

#endif // VISITORMODIFICA_H
