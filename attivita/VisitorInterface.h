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

    virtual void visit(const Evento&) = 0;
    virtual void visit(const Lettura&) = 0;
    virtual void visit(const Promemoria&) = 0;
    virtual void visit(const Riunione&) = 0;
    virtual void visit(const Viaggio&) = 0;
};

#endif // VISITORINTERFACE_H
