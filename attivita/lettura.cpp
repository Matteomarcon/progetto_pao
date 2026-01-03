#include "lettura.h"

Lettura::Lettura(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QString stato, int priorita, QString autore, int pagine, QString lingua):
    AttivitaLibera(titolo, descrizioneBreve, dataCreazione, ultimaModifica, stato, priorita), autore(autore), pagine(pagine), lingua(lingua) {}

QString Lettura::getAutore() const {return autore;}
int Lettura::getPagine() const {return pagine;}
QString Lettura::getLingua() const {return lingua;}

void Lettura::setAutore(QString autore) {this->autore = autore;}
void Lettura::setPagine(int pagine) {this->pagine = pagine;}
void Lettura::setLingua(QString lingua) {this->lingua = lingua;}

void Lettura::accept(VisitorInterface& visitor){
    visitor.visit(*this);
}
void Lettura::accept(VisitorModifica& visitor){
    visitor.visit(*this);
}

void Lettura::toJson(QJsonObject& obj) const {
    obj["attivita"] = "Lettura";
    obj["titolo"] = this->getTitolo();
    obj["descrizioneBreve"] =  this->getDescrizioneBreve();
    obj["dataCreazione"] =  this->getDataCreazione().toString();
    obj["ultimaModifica"] = this->getUltimaModifica().toString();
    obj["stato"] = this->getStato();
    obj["priorita"] = QString::number(this->getPriorita());
    obj["autore"] = this->getAutore();
    obj["pagine"] = this->getPagine();
    obj["lingua"] = this->getLingua();
}
void Lettura::toXml(QDomElement& elm) const {
}
