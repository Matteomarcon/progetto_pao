#ifndef VISTACALENDARIO_H
#define VISTACALENDARIO_H

#include "attivita/attivita.h"

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QLocale>

class VistaCalendario : public QWidget {
    Q_OBJECT
signals:
    void chiudi();
private:
    QCalendarWidget* calendario;
    QLabel* labelDescrizione;
    QMap<QDate, int> giorniConAttivita;
    void onDataSelezionata(const QDate&);

    QPushButton* bottoneChiudi;
    QList<Attivita*> listaAttivita;
public:
    VistaCalendario(QList<Attivita*>, QWidget* parent = nullptr);
    void aggiornaCalendario(const QList<Attivita*>&);
};

#endif // VISTACALENDARIO_H
