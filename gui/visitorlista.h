#ifndef VISITORLISTA_H
#define VISITORLISTA_H

#include <QListWidgetItem>

#include <attivita/VisitorInterface.h>
#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorLista : public VisitorInterface {
private:
    QListWidgetItem* item;
public:
    QListWidgetItem* getItem();

    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORLISTA_H
