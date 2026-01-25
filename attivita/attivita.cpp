#include "attivita.h"

Attivita::Attivita(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica):
    titolo(titolo), descrizioneBreve(descrizioneBreve), dataCreazione(dataCreazione), ultimaModifica(ultimaModifica) {}

QString Attivita::getTitolo() const {return titolo;}
QString Attivita::getDescrizioneBreve() const {return descrizioneBreve;}
QDateTime Attivita::getDataCreazione() const {return dataCreazione;}
QDateTime Attivita::getUltimaModifica() const {return ultimaModifica;}

void Attivita::setTitolo(const QString& titolo) {this->titolo = titolo;}
void Attivita::setDescrizioneBreve(const QString& descrizioneBreve) {this->descrizioneBreve = descrizioneBreve;}
void Attivita::setUltimaModifica(const QDateTime& ultimaModifica) {this->ultimaModifica = ultimaModifica;}

