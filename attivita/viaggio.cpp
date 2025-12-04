#include "viaggio.h"

Viaggio::Viaggio(QString titolo, QString descrizioneBreve, QDateTime dataCreazione, QDateTime ultimaModifica, QDateTime dataInizio, QDateTime dataFine, QString mezzoDiTrasporto, QString luogoPartenza):
    AttivitaProgrammata(titolo, descrizioneBreve, dataCreazione, ultimaModifica, dataInizio, dataFine), mezzoDiTrasporto(mezzoDiTrasporto), luogoPartenza(luogoPartenza) {}

QString Viaggio::getMezzoDiTrasporto() const {return mezzoDiTrasporto;}
QString Viaggio::getLuogoPartenza() const {return luogoPartenza;}

void Viaggio::setMezzoDiTrasporto(QString mezzoDiTrasporto) {this->mezzoDiTrasporto = mezzoDiTrasporto;}
void Viaggio::setLuogoPartenza(QString luogoPartenza) {this->luogoPartenza = luogoPartenza;}

void Viaggio::accept(VisitorInterface& visitor){
    visitor.visit(*this);
}
void Viaggio::accept(VisitorModifica& visitor){
    visitor.visit(*this);
}

void Viaggio::toJson(QJsonObject& obj) const {
}
void Viaggio::toXml(QDomElement& elm) const {
}
