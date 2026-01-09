#ifndef VISITORMATCH_H
#define VISITORMATCH_H

#include <QString>
#include <QDateTime>

#include "attivita/VisitorInterface.h"
#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class VisitorMatch: public VisitorInterface {
private:
    bool match;
    QString tipoAttivita;
    QDateTime dataInizio;
    QDateTime dataFine;
public:
    VisitorMatch(const QString&, const QDateTime&, const QDateTime&);
    bool getMatch();

    virtual void visit(const Evento&);
    virtual void visit(const Lettura&);
    virtual void visit(const Promemoria&);
    virtual void visit(const Riunione&);
    virtual void visit(const Viaggio&);
};

#endif // VISITORMATCH_H
