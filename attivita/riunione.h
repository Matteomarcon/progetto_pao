#ifndef RIUNIONE_H
#define RIUNIONE_H

#include "attivitaprogrammata.h"

class Riunione : public AttivitaProgrammata {
private:
    QString ordineDelGiorno;
    QString url;
public:
    Riunione(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString ordineDelGiorno, QString url);
    virtual ~Riunione() {};
};

#endif // RIUNIONE_H
