#include "gestorejson.h"

GestoreJson::GestoreJson(const QString& path): path(path) {}

void GestoreJson::apriJSON() {
    QFile file(path);
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
    }
}

bool GestoreJson::salvaJSON() {
    QJsonArray array;
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
    return true;
}

const QList<Attivita*>& GestoreJson::getListaAttivita() const {
    return listaAttivita;
}

void GestoreJson::setListaAttivita(QList<Attivita*> nuovaLista) {
    listaAttivita = nuovaLista;
}

Evento* GestoreJson::creaEvento(const QJsonObject& obj) {
    return new Evento(
        obj.value("titolo").toString(),
        obj.value("descrizioneBreve").toString(),
        QDateTime::fromString(obj.value("dataCreazione").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("ultimaModifica").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataInizio").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataFine").toString(), Qt::ISODate),
        obj.value("organizzatore").toString(),
        obj.value("luogo").toString());
}

Lettura* GestoreJson::creaLettura(const QJsonObject& obj) {
    return new Lettura(
        obj.value("titolo").toString(),
        obj.value("descrizioneBreve").toString(),
        QDateTime::fromString(obj.value("dataCreazione").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("ultimaModifica").toString(), Qt::ISODate),
        obj.value("stato").toString(),
        obj.value("priorita").toInt(),
        obj.value("autore").toString(),
        obj.value("pagine").toInt(),
        obj.value("lingua").toString());
}

Promemoria* GestoreJson::creaPromemoria(const QJsonObject& obj) {
    return new Promemoria(
        obj.value("titolo").toString(),
        obj.value("descrizioneBreve").toString(),
        QDateTime::fromString(obj.value("dataCreazione").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("ultimaModifica").toString(), Qt::ISODate),
        obj.value("stato").toString(),
        obj.value("priorita").toInt(),
        obj.value("nota").toString());
}

Riunione* GestoreJson::creaRiunione(const QJsonObject& obj) {
    return new Riunione(
        obj.value("titolo").toString(),
        obj.value("descrizioneBreve").toString(),
        QDateTime::fromString(obj.value("dataCreazione").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("ultimaModifica").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataInizio").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataFine").toString(), Qt::ISODate),
        obj.value("ordineDelGiorno").toString(),
        obj.value("url").toString());
}

Viaggio* GestoreJson::creaViaggio(const QJsonObject& obj) {
    return new Viaggio(
        obj.value("titolo").toString(),
        obj.value("descrizioneBreve").toString(),
        QDateTime::fromString(obj.value("dataCreazione").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("ultimaModifica").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataInizio").toString(), Qt::ISODate),
        QDateTime::fromString(obj.value("dataFine").toString(), Qt::ISODate),
        obj.value("mezzoDiTrasporto").toString(),
        obj.value("luogoPartenza").toString());
}
