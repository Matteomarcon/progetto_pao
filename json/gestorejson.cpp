#include "gestorejson.h"

GestoreJson::GestoreJson(const QString& path): path(path) {}

void GestoreJson::apriJSON() {

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
