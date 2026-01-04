#ifndef GESTOREXML_H
#define GESTOREXML_H

#include <QObject>
#include <QFile>

#include "attivita/evento.h"
#include "attivita/lettura.h"
#include "attivita/promemoria.h"
#include "attivita/riunione.h"
#include "attivita/viaggio.h"

class GestoreXml: public QObject {
    Q_OBJECT
private:
    QList<Attivita*> listaAttivita;
    QString path;

    Evento* creaEvento(const QDomElement&);
    Lettura* creaLettura(const QDomElement&);
    Promemoria* creaPromemoria(const QDomElement&);
    Riunione* creaRiunione(const QDomElement&);
    Viaggio* creaViaggio(const QDomElement&);
public:
    GestoreXml(const QString&);

    const QList<Attivita*>& getListaAttivita() const;
    void setListaAttivita(QList<Attivita*>);

    void apriXml();
    bool salvaXml();
};

#endif // GESTOREXML_H
