#include "evento.h"

Evento::Evento(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString organizzatore, QString luogo):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), organizzatore(organizzatore), luogo(luogo) {}

QString Evento::getOrganizzatore() const {return organizzatore;}
QString Evento::getLuogo() const {return luogo;}

void Evento::setOrganizzatore(QString organizzatore) {this->organizzatore = organizzatore;}
void Evento::setLuogo(QString luogo) {this->luogo = luogo;}

void Evento::accept(VisitorInterface& visitor){
    visitor.visit(*this);
}
void Evento::accept(VisitorModifica& visitor){
    visitor.visit(*this);
}

void Evento::toJson(QJsonObject& obj) const {
}
void Evento::toXml(QDomElement& elm) const {
}
