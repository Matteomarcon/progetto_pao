#ifndef VISITORLABEL_H
#define VISITORLABEL_H

#include <attivita/VisitorInterface.h>

#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorLabel : public VisitorInterface {
private:
    QList<QString> listaLabel;
public:
    QList<QString> getListaLabel();

    void labelAttivita(const Attivita&);
    void labelAttivitaLibera(const AttivitaLibera&);
    void labelAttivitaProgrammata(const AttivitaProgrammata&);
    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORLABEL_H
