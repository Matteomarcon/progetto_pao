#ifndef ATTIVITAPROGRAMMATA_H
#define ATTIVITAPROGRAMMATA_H

#include "attivita.h"

class AttivitaProgrammata : public Attivita {
private:
    QDateTime dataInizio;
    QDateTime dataFine;
public:
    AttivitaProgrammata(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine);
    virtual ~AttivitaProgrammata() {};

    QDateTime getDataInizio() const;
    QDateTime getDataFine() const;
    void setDataInizio(QDateTime);
    void setDataFine(QDateTime);
};

#endif // ATTIVITAPROGRAMMATA_H
