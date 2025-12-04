#include "lettura.h"

Lettura::Lettura(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString autore, int pagine, QString lingua):
    AttivitaLibera(titolo, descrizioneBreve, dataCreazione, ultimaModifica, stato, priorita), autore(autore), pagine(pagine), lingua(lingua) {}

QString Lettura::getAutore() const {return autore;}
int Lettura::getPagine() const {return pagine;}
QString Lettura::getLingua() const {return lingua;}

void Lettura::setAutore(QString autore) {this->autore = autore;}
void Lettura::setPagine(int pagine) {this->pagine = pagine;}
void Lettura::setLingua(QString lingua) {this->lingua = lingua;}
