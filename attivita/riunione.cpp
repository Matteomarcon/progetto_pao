#include "riunione.h"

Riunione::Riunione(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString ordineDelGiorno, QString url):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), ordineDelGiorno(ordineDelGiorno), url(url) {}
