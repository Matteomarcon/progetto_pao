#ifndef ATTIVITALIBERA_H
#define ATTIVITALIBERA_H

#include "attivita.h"

class AttivitaLibera : public Attivita {
private:
    int stato;
    int priorita;
public:
    AttivitaLibera(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita);
    virtual ~AttivitaLibera() {};

    int getStato() const;
    int getPriorita() const;
    void setStato(int);
    void setPriorita(int);
};

#endif // ATTIVITALIBERA_H
