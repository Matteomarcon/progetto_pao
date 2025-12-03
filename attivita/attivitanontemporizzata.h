#ifndef ATTIVITANONTEMPORIZZATA_H
#define ATTIVITANONTEMPORIZZATA_H

#include "Attivita.h"

class AttivitaNonTemporizzata : public Attivita {
private:
    bool stato;
    int priorita;
public:
    AttivitaNonTemporizzata();
};

#endif // ATTIVITANONTEMPORIZZATA_H
