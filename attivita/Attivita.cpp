#include "Attivita.h"

Attivita::Attivita(QString titolo, QString descrizione, QDateTime dataCreazione):
    titolo(titolo), descrizione(descrizione), dataCreazione(dataCreazione) {} //Costruttore da definire in base agli attributi

//Metodi get e set da inserire in base agli attributi
QString Attivita::getTitolo() const {return titolo;}
QString Attivita::getDescrizione() const {return descrizione;}
QDateTime Attivita::getDataCreazione() const {return dataCreazione;}

void Attivita::setTitolo(QString titolo) {this->titolo = titolo;}
void Attivita::setDescrizione(QString descrizione) {this->descrizione = descrizione;}
void Attivita::setDataCreazione(QDateTime dataCreazione) {this->dataCreazione = dataCreazione;}
