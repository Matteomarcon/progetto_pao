#ifndef ATTIVITATEMPORIZZATA_H
#define ATTIVITATEMPORIZZATA_H

#include "Attivita.h"

class AttivitaTemporizzata : public Attivita {
private:
    QDateTime dataInizio;
    QDateTime dataFine;
public:
    AttivitaTemporizzata();
};

#endif // ATTIVITATEMPORIZZATA_H
