#ifndef EVENTO_H
#define EVENTO_H

#include "attivita/Attivita.h"

class Evento : public Attivita {
private:
    QDateTime dataInizio;
    QDateTime dataFine;
    QString luogo;
public:
    Evento();
};

#endif // EVENTO_H
