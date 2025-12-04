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

    virtual void accept(VisitorInterface&);
    virtual void accept(VisitorModifica&);

    virtual void toJson(QJsonObject&) const;
    virtual void toXml(QDomElement&) const;
};

#endif // VIAGGIO_H
