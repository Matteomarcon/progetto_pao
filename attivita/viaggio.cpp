#include "viaggio.h"

Viaggio::Viaggio(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString mezzoDiTrasporto, QString luogoPartenza):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), mezzoDiTrasporto(mezzoDiTrasporto), luogoPartenza(luogoPartenza) {}
