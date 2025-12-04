#ifndef VIAGGIO_H
#define VIAGGIO_H

#include "attivitaprogrammata.h"

class Viaggio : public AttivitaProgrammata {
private:
    QString mezzoDiTrasporto;
    QString luogoPartenza;
public:
    Viaggio(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString mezzoDiTrasporto, QString luogoPartenza);
    virtual ~Viaggio() {};

    QString getMezzoDiTrasporto() const;
    QString getLuogoPartenza() const;
    void setMezzoDiTrasporto(QString);
    void setLuogoPartenza(QString);
};

#endif // VIAGGIO_H
