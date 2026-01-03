#include "promemoria.h"

Promemoria::Promemoria(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QString stato, int priorita, QString nota):
    AttivitaLibera(titolo, descrizioneBreve, dataCreazione, ultimaModifica, stato, priorita), nota(nota) {}

QString Promemoria::getNota() const {return nota;}

void Promemoria::setNota(QString nota) {this->nota = nota;}

void Promemoria::accept(VisitorInterface& visitor){
    visitor.visit(*this);
}
void Promemoria::accept(VisitorModifica& visitor){
    visitor.visit(*this);
}

void Promemoria::toJson(QJsonObject& obj) const {
    obj["attivita"] = "Promemoria";
    obj["titolo"] = this->getTitolo();
    obj["descrizioneBreve"] =  this->getDescrizioneBreve();
    obj["dataCreazione"] =  this->getDataCreazione().toString(Qt::ISODate);
    obj["ultimaModifica"] = this->getUltimaModifica().toString(Qt::ISODate);
    obj["stato"] = this->getStato();
    obj["priorita"] = QString::number(this->getPriorita());
    obj["nota"] = this->getNota();
}
void Promemoria::toXml(QDomElement& elm) const {
}
