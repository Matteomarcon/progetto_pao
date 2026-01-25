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

    QString getOrdineDelGiorno() const;
    QString getUrl() const;
    void setOrdineDelGiorno(const QString&);
    void setUrl(const QString&);

    virtual void accept(ConstVisitorInterface&) const;
    virtual void accept(VisitorInterface&);

    virtual void toJson(QJsonObject&) const;
    virtual void toXml(QDomElement&) const;
};

#endif // RIUNIONE_H
