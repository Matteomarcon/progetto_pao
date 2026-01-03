#ifndef GESTOREJSON_H
#define GESTOREJSON_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class GestoreJson : public QObject {
    Q_OBJECT
private:
    QList<Attivita*> listaAttivita;
    QString path;
public:
    GestoreJson(const QString&);

    const QList<Attivita*>& getListaAttivita() const;
    void setListaAttivita(QList<Attivita*>);

    void apriJSON();
    bool salvaJSON();

    Evento* creaEvento(const QJsonObject&);
    Lettura* creaLettura(const QJsonObject&);
    Promemoria* creaPromemoria(const QJsonObject&);
    Riunione* creaRiunione(const QJsonObject&);
    Viaggio* creaViaggio(const QJsonObject&);
};

#endif // GESTOREJSON_H
