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
    obj["dataCreazione"] =  this->getDataCreazione().toString(Qt::ISODate);
    obj["ultimaModifica"] = this->getUltimaModifica().toString(Qt::ISODate);
    obj["stato"] = this->getStato();
    obj["priorita"] = this->getPriorita();
    obj["autore"] = this->getAutore();
    obj["pagine"] = this->getPagine();
    obj["lingua"] = this->getLingua();
}

void Lettura::toXml(QDomElement& elm) const {
    elm.setAttribute("titolo", this->getTitolo());
    elm.setAttribute("descrizioneBreve", this->getDescrizioneBreve());
    elm.setAttribute("dataCreazione", this->getDataCreazione().toString(Qt::ISODate));
    elm.setAttribute("ultimaModifica", this->getUltimaModifica().toString(Qt::ISODate));
    elm.setAttribute("stato", this->getStato());
    elm.setAttribute("priorita", this->getPriorita());
    elm.setAttribute("autore", this->getAutore());
    elm.setAttribute("pagine", this->getPagine());
    elm.setAttribute("lingua", this->getLingua());
}
