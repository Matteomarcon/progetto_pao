#ifndef VISTALISTAATTIVITA_H
#define VISTALISTAATTIVITA_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>

#include "attivita/attivita.h"

#include "visitorlistaattivita.h"

class VistaListaAttivita : public QWidget {
    Q_OBJECT
signals:
    void itemSelezionato(Attivita* a);
private:
    QList<Attivita*> listaAttivita;
    QListWidget* widgetLista;
    std::map<QListWidgetItem*, Attivita*> mappaItemAttivita;
public:
    VistaListaAttivita(QList<Attivita*>, QWidget *parent = nullptr);

    void aggiornaLista(const QList<Attivita*>&);

    //void filterItems(const QString&, const QSet<QString>&, const int&, const int&);
    //void filterDate(const int&);
};

#endif // VISTALISTAATTIVITA_H
