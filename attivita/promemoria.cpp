#include "promemoria.h"

Promemoria::Promemoria(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString nota):
    AttivitaLibera(titolo, descrizioneBreve, dataCreazione, ultimaModifica, stato, priorita), nota(nota) {}
