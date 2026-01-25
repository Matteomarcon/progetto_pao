#ifndef ATTIVITA_H
#define ATTIVITA_H

#include "ConstVisitorInterface.h"
#include "VisitorInterface.h"

#include <QJsonObject>
#include <QDomDocument>

class Attivita {
private:
    QString titolo;
    QString descrizioneBreve;
    const QDateTime dataCreazione;
    QDateTime ultimaModifica;
public:
    Attivita(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica);
    virtual ~Attivita() {};

    QString getTitolo() const;
    QString getDescrizioneBreve() const;
    QDateTime getDataCreazione() const;
    QDateTime getUltimaModifica() const;
    void setTitolo(const QString&);
    void setDescrizioneBreve(const QString&);
    void setUltimaModifica(const QDateTime&);

    virtual void accept(ConstVisitorInterface&) const = 0;
    virtual void accept(VisitorInterface&) = 0;
    virtual void toJson(QJsonObject&) const = 0;
    virtual void toXml(QDomElement&) const = 0;
};

#endif // ATTIVITA_H
