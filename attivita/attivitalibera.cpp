#include "attivitalibera.h"

AttivitaLibera::AttivitaLibera(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita):
    Attivita(titolo, descrizioneBreve, dataCreazione, ultimaModifica), stato(stato), priorita(priorita) {}

int AttivitaLibera::getStato() const {return stato;}
int AttivitaLibera::getPriorita() const {return priorita;}

void AttivitaLibera::setStato(int stato) {this->stato = stato;}
void AttivitaLibera::setPriorita(int priorita) {this->priorita = priorita;}
