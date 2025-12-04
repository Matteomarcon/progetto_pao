#ifndef VISTALISTAATTIVITA_H
#define VISTALISTAATTIVITA_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>

#include "attivita/attivita.h"

class VistaListaAttivita : public QWidget {
    Q_OBJECT
private:
    QList<Attivita*> listaAttivita;
    QListWidget* widgetLista;
    std::map<QListWidgetItem*, Attivita*> itemMap;
public:
    VistaListaAttivita(QList<Attivita*>, QWidget *parent = nullptr);
    /*void filterItems(const QString&, const QSet<QString>&, const int&, const int&);
    void filterDate(const int&);
    void refresh(const QList<Component*>&);*/
signals:
    void itemSelezionato(Attivita* a);
};

#endif // VISTALISTAATTIVITA_H
