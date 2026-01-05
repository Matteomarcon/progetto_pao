#include "GestoreXml.h"

GestoreXml::GestoreXml(const QString& path): path(path) {}

const QList<Attivita*>& GestoreXml::getListaAttivita() const {
    return listaAttivita;
}

void GestoreXml::setListaAttivita(QList<Attivita*> nuovaLista) {
    listaAttivita = nuovaLista;
}

void GestoreXml::apriXml() {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossibile aprire il file:" << path;
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "Errore nel parsing XML";
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    if (root.tagName() != "attivita") {
        qWarning() << "Root XML non valido";
        return;
    }

    QDomNode n = root.firstChild();
    while (!n.isNull()) {
        QDomElement elm = n.toElement();
        if (!elm.isNull()) {
            QString tipoAttivita = elm.tagName();
            Attivita *attivita = nullptr;

            if (tipoAttivita == "Evento")
                attivita = creaEvento(elm);
            if (tipoAttivita == "Lettura")
                attivita = creaLettura(elm);
            if (tipoAttivita == "Promemoria")
                attivita = creaPromemoria(elm);
            if (tipoAttivita == "Riunione")
                attivita = creaRiunione(elm);
            if (tipoAttivita == "Viaggio")
                attivita = creaViaggio(elm);
            if (attivita)
                listaAttivita.append(attivita);
            else
                qWarning() << "Non esiste l'attività: " << tipoAttivita;
        }
        n = n.nextSibling();
    }
}

bool GestoreXml::salvaXml() {
    QDomDocument doc;
    QDomElement root = doc.createElement("attivita");
    doc.appendChild(root);

    for (auto attivita : listaAttivita) {
        QString tipoAttivita;
        if (dynamic_cast<Evento*>(attivita))
            tipoAttivita = "Evento";
        else if (dynamic_cast<Lettura*>(attivita))
            tipoAttivita = "Lettura";
        else if (dynamic_cast<Promemoria*>(attivita))
            tipoAttivita = "Promemoria";
        else if (dynamic_cast<Riunione*>(attivita))
            tipoAttivita = "Riunione";
        else if (dynamic_cast<Viaggio*>(attivita))
            tipoAttivita = "Viaggio";
        else {
            qWarning() << "Non esiste l'attività: " << tipoAttivita;
            continue;
        }
        QDomElement elm = doc.createElement(tipoAttivita);
        attivita->toXml(elm);
        root.appendChild(elm);
    }

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    doc.save(stream, 4);
    file.close();
    return true;
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
