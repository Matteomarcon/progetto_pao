#ifndef LETTURA_H
#define LETTURA_H

#include "attivitalibera.h"

class Lettura : public AttivitaLibera {
private:
    QString autore;
    int pagine;
    QString lingua;
public:
    Lettura(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString autore, int pagine, QString lingua);
    virtual ~Lettura() {};

    QString getAutore() const;
    int getPagine() const;
    QString getLingua() const;
    void setAutore(QString);
    void setPagine(int);
    void setLingua(QString);
};

#endif // LETTURA_H
