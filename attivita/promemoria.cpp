#include "promemoria.h"

Promemoria::Promemoria(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, int stato, int priorita, QString nota):
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
}
void Promemoria::toXml(QDomElement& elm) const {
}
