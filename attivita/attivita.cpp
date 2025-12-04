#include "attivita.h"

Attivita::Attivita(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica):
    titolo(titolo), descrizioneBreve(descrizioneBreve), dataCreazione(dataCreazione), ultimaModifica(ultimaModifica) {}

QString Attivita::getTitolo() const {return titolo;}
QString Attivita::getDescrizioneBreve() const {return descrizioneBreve;}
QDateTime Attivita::getDataCreazione() const {return dataCreazione;}
QDateTime Attivita::getUltimaModifica() const {return ultimaModifica;}

void Attivita::setTitolo(QString titolo) {this->titolo = titolo;}
void Attivita::setDescrizioneBreve(QString descrizioneBreve) {this->descrizioneBreve = descrizioneBreve;}
void Attivita::setDataCreazione(QDateTime dataCreazione) {this->dataCreazione = dataCreazione;}
void Attivita::setUltimaModifica(QDateTime ultimaModifica) {this->ultimaModifica = ultimaModifica;}

