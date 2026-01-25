#ifndef VISITORINTERFACE_H
#define VISITORINTERFACE_H

class Evento;
class Lettura;
class Promemoria;
class Riunione;
class Viaggio;

class VisitorInterface {
public:
    virtual ~VisitorInterface() = default;

    virtual void visit(Evento&) = 0;
    virtual void visit(Lettura&) = 0;
    virtual void visit(Promemoria&) = 0;
    virtual void visit(Riunione&) = 0;
    virtual void visit(Viaggio&) = 0;
};

#endif // VISITORINTERFACE_H
