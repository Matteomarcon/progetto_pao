#ifndef LETTURA_H
#define LETTURA_H

#include "attivitalibera.h"

class Lettura : public AttivitaLibera {
private:
    QString autore;
    int pagine;
    QString lingua;
public:
    Lettura(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QString stato, int priorita, QString autore, int pagine, QString lingua);
    virtual ~Lettura() {};

    QString getAutore() const;
    int getPagine() const;
    QString getLingua() const;
    void setAutore(const QString&);
    void setPagine(const int&);
    void setLingua(const QString&);

    virtual void accept(ConstVisitorInterface&) const;
    virtual void accept(VisitorInterface&);

    virtual void toJson(QJsonObject&) const;
    virtual void toXml(QDomElement&) const;
};

#endif // LETTURA_H
