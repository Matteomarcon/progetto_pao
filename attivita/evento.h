#ifndef EVENTO_H
#define EVENTO_H

#include "attivitaprogrammata.h"

class Evento : public AttivitaProgrammata {
private:
    QString organizzatore;
    QString luogo;
public:
    Evento(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString organizzatore, QString luogo);
    virtual ~Evento() {};

    QString getOrganizzatore() const;
    QString getLuogo() const;
    void setOrganizzatore(QString);
    void setLuogo(QString);
};

#endif // EVENTO_H
