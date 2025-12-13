#ifndef ATTIVITALIBERA_H
#define ATTIVITALIBERA_H

#include "attivita.h"

class AttivitaLibera : public Attivita {
private:
    QString stato;
    int priorita;
public:
    AttivitaLibera(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QString stato, int priorita);
    virtual ~AttivitaLibera() {};

    QString getStato() const;
    int getPriorita() const;
    void setStato(QString);
    void setPriorita(int);
};

#endif // ATTIVITALIBERA_H
