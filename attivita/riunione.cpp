#include "riunione.h"

Riunione::Riunione(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString ordineDelGiorno, QString url):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), ordineDelGiorno(ordineDelGiorno), url(url) {}

QString Riunione::getOrdineDelGiorno() const {return ordineDelGiorno;}
QString Riunione::getUrl() const {return url;}

void Riunione::setOrdineDelGiorno(QString ordineDelGiorno) {this->ordineDelGiorno = ordineDelGiorno;}
void Riunione::setUrl(QString url) {this->url = url;}

void Riunione::accept(VisitorInterface& visitor){
    visitor.visit(*this);
}
void Riunione::accept(VisitorModifica& visitor){
    visitor.visit(*this);
}

void Riunione::toJson(QJsonObject& obj) const {
    obj["attivita"] = "Riunione";
    obj["titolo"] = this->getTitolo();
    obj["descrizioneBreve"] =  this->getDescrizioneBreve();
    obj["dataCreazione"] =  this->getDataCreazione().toString(Qt::ISODate);
    obj["ultimaModifica"] = this->getUltimaModifica().toString(Qt::ISODate);
    obj["dataInizio"] = this->getDataInizio().toString(Qt::ISODate);
    obj["dataFine"] = this->getDataFine().toString(Qt::ISODate);
    obj["ordineDelGiorno"] = this->getOrdineDelGiorno();
    obj["url"] = this->getUrl();
}

void Riunione::toXml(QDomElement& elm) const {
    elm.setAttribute("titolo", this->getTitolo());
    elm.setAttribute("descrizioneBreve", this->getDescrizioneBreve());
    elm.setAttribute("dataCreazione", this->getDataCreazione().toString(Qt::ISODate));
    elm.setAttribute("ultimaModifica", this->getUltimaModifica().toString(Qt::ISODate));
    elm.setAttribute("dataInizio", this->getDataInizio().toString(Qt::ISODate));
    elm.setAttribute("dataFine", this->getDataFine().toString(Qt::ISODate));
    elm.setAttribute("ordineDelGiorno", this->getOrdineDelGiorno());
    elm.setAttribute("url", this->getUrl());
}

