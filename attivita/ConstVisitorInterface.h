#ifndef CONSTVISITORINTERFACE_H
#define CONSTVISITORINTERFACE_H

class Evento;
class Lettura;
class Promemoria;
class Riunione;
class Viaggio;

class ConstVisitorInterface {
public:
    virtual ~ConstVisitorInterface() = default;

    virtual void visit(const Evento&) = 0;
    virtual void visit(const Lettura&) = 0;
    virtual void visit(const Promemoria&) = 0;
    virtual void visit(const Riunione&) = 0;
    virtual void visit(const Viaggio&) = 0;
};

#endif // CONSTVISITORINTERFACE_H
