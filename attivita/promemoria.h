#ifndef PROMEMORIA_H
#define PROMEMORIA_H

#include "attivitalibera.h"

class Promemoria : public AttivitaLibera {
private:
    QString nota;
public:
    Promemoria(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString nota);
    virtual ~Promemoria() {};
};

#endif // PROMEMORIA_H
