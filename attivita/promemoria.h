#ifndef PROMEMORIA_H
#define PROMEMORIA_H

#include "attivitalibera.h"

class Promemoria : public AttivitaLibera {
private:
    QString nota;
public:
    Promemoria(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString nota);
    virtual ~Promemoria() {};

    QString getNota() const;
    void setNota(QString);

    virtual void accept(VisitorInterface&);
    virtual void accept(VisitorModifica&);

    virtual void toJson(QJsonObject&) const;
    virtual void toXml(QDomElement&) const;
};

#endif // PROMEMORIA_H
