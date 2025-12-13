#include "attivitalibera.h"

AttivitaLibera::AttivitaLibera(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QString stato, int priorita):
    Attivita(titolo, descrizioneBreve, dataCreazione, ultimaModifica), stato(stato), priorita(priorita) {}

QString AttivitaLibera::getStato() const {return stato;}
int AttivitaLibera::getPriorita() const {return priorita;}

void AttivitaLibera::setStato(QString stato) {this->stato = stato;}
void AttivitaLibera::setPriorita(int priorita) {this->priorita = priorita;}
