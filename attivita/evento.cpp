#include "evento.h"

Evento::Evento(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString organizzatore, QString luogo):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), organizzatore(organizzatore), luogo(luogo) {}
