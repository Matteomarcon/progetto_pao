#include "lettura.h"

Lettura::Lettura(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString autore, int pagine, QString lingua):
    AttivitaLibera(titolo, descrizioneBreve, dataCreazione, ultimaModifica, stato, priorita), autore(autore), pagine(pagine), lingua(lingua) {}

