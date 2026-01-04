#include "GestoreXml.h"

GestoreXml::GestoreXml(const QString& path): path(path) {}

const QList<Attivita*>& GestoreXml::getListaAttivita() const {
    return listaAttivita;
}

void GestoreXml::setListaAttivita(QList<Attivita*> nuovaLista) {
    listaAttivita = nuovaLista;
}


void GestoreXml::apriXml() {
/*    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossibile aprire il file:" << path;
        return;
    }

    QByteArray jsonDataArray = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(jsonDataArray);

    if (!doc.isArray()) {
        qWarning() << "Il file JSON non contiene un array";
        return;
    }

    QJsonArray jsonArray = doc.array();

    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            QString tipoAttivita = obj["attivita"].toString();
            Attivita* attivita = nullptr;
            if (tipoAttivita == "Evento")
                attivita = creaEvento(obj);
            if (tipoAttivita == "Lettura")
                attivita = creaLettura(obj);
            if (tipoAttivita == "Promemoria")
                attivita = creaPromemoria(obj);
            if (tipoAttivita == "Riunione")
                attivita = creaRiunione(obj);
            if (tipoAttivita == "Viaggio")
                attivita = creaViaggio(obj);
            if (attivita)
                listaAttivita.append(attivita);
            else
                qWarning() << "Non esiste l'attivita: " << attivita;
        } else
            qWarning() << "Value non è un oggetto";
    }*/
}

bool GestoreXml::salvaXml() {
/*    QJsonArray array;
    for (auto attivita : listaAttivita) {
        QJsonObject obj;
        attivita->toJson(obj);
        array.append(obj);
    }

    QJsonDocument doc(array);
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly))
        return false;
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;*/
}

Evento* GestoreXml::creaEvento(const QDomElement& elm) {
    return new Evento(
        elm.attribute("titolo"),
        elm.attribute("descrizioneBreve"),
        QDateTime::fromString(elm.attribute("dataCreazione"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("ultimaModifica"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataInizio"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataFine"), Qt::ISODate),
        elm.attribute("organizzatore"),
        elm.attribute("luogo"));
}

Lettura* GestoreXml::creaLettura(const QDomElement& elm) {
    return new Lettura(
        elm.attribute("titolo"),
        elm.attribute("descrizioneBreve"),
        QDateTime::fromString(elm.attribute("dataCreazione"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("ultimaModifica"), Qt::ISODate),
        elm.attribute("stato"),
        elm.attribute("priorita").toInt(),
        elm.attribute("autore"),
        elm.attribute("pagine").toInt(),
        elm.attribute("lingua"));
}

Promemoria* GestoreXml::creaPromemoria(const QDomElement& elm) {
    return new Promemoria(
        elm.attribute("titolo"),
        elm.attribute("descrizioneBreve"),
        QDateTime::fromString(elm.attribute("dataCreazione"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("ultimaModifica"), Qt::ISODate),
        elm.attribute("stato"),
        elm.attribute("priorita").toInt(),
        elm.attribute("nota"));
}

Riunione* GestoreXml::creaRiunione(const QDomElement& elm) {
    return new Riunione(
        elm.attribute("titolo"),
        elm.attribute("descrizioneBreve"),
        QDateTime::fromString(elm.attribute("dataCreazione"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("ultimaModifica"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataInizio"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataFine"), Qt::ISODate),
        elm.attribute("ordineDelGiorno"),
        elm.attribute("url"));
}

Viaggio* GestoreXml::creaViaggio(const QDomElement& elm) {
    return new Viaggio(
        elm.attribute("titolo"),
        elm.attribute("descrizioneBreve"),
        QDateTime::fromString(elm.attribute("dataCreazione"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("ultimaModifica"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataInizio"), Qt::ISODate),
        QDateTime::fromString(elm.attribute("dataFine"), Qt::ISODate),
        elm.attribute("mezzoDiTrasporto"),
        elm.attribute("luogoPartenza"));
}
