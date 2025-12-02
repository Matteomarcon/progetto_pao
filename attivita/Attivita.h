#ifndef ATTIVITA_H
#define ATTIVITA_H

#include "VisitorInterface.h"
#include "VisitorModifica.h"

#include <QJsonObject>
#include <QDomDocument>

class Attivita {
private:
    //Attributi da definire
    QString titolo;
    QString descrizione;
    QDateTime dataCreazione;
    bool completata;
public:
    Attivita(QString titolo, QString descrizione, QDateTime dataCreazione, bool completata); //Costruttore da definire in base agli attributi
    virtual ~Attivita() {};

    //Metodi get e set da inserire in base agli attributi
    QString getTitolo() const;
    QString getDescrizione() const;
    QDateTime getDataCreazione() const;
    bool getCompletata() const;
    void setTitolo(QString);
    void setDescrizione(QString);
    void setDataCreazione(QDateTime);
    void setCompletata(bool);

    virtual void accept(VisitorInterface&) = 0;
    virtual void accept(VisitorModifica&) = 0;
    virtual void toJson(QJsonObject&) const = 0;
    virtual void toXml(QDomElement&) const = 0;
};

#endif // ATTIVITA_H

//Idea figli: ramo attività a calendario (evento, riunione, viaggio) e ramo "da fare" (promemoria, scadenza)
