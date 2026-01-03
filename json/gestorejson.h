#ifndef GESTOREJSON_H
#define GESTOREJSON_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

#include "attivita/attivita.h"

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
};

#endif // GESTOREJSON_H
