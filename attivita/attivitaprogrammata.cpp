#include "attivitaprogrammata.h"

AttivitaProgrammata::AttivitaProgrammata(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine):
    Attivita(titolo, descrizioneBreve, dataCreazione, ultimaModifica), dataInizio(dataInizio), dataFine(dataFine) {}

QDateTime AttivitaProgrammata::getDataInizio() const {return dataInizio;}
QDateTime AttivitaProgrammata::getDataFine() const {return dataFine;}

void AttivitaProgrammata::setDataInizio(QDateTime dataInizio) {this->dataInizio = dataInizio;}
void AttivitaProgrammata::setDataFine(QDateTime dataFine) {this->dataFine = dataFine;}
