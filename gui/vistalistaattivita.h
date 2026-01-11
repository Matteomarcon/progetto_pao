#ifndef VISTALISTAATTIVITA_H
#define VISTALISTAATTIVITA_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>

#include "attivita/attivita.h"

#include "visitorlistaattivita.h"
#include "visitormatch.h"

class VistaListaAttivita : public QWidget {
    Q_OBJECT
signals:
    void itemSelezionato(Attivita* a);
private:
    QList<Attivita*> listaAttivita;
    QListWidget* widgetLista;
    std::map<QListWidgetItem*, Attivita*> mappaItemAttivita;
public:
    VistaListaAttivita(const QList<Attivita*>&, QWidget* parent = nullptr);

    void aggiornaLista(const QList<Attivita*>&);
    void deseleziona();

    void filtra(const QString&, const QString&, const QDateTime&, const QDateTime&);
};

#endif // VISTALISTAATTIVITA_H
