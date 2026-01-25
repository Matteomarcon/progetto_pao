#ifndef WIDGETFILTRI_H
#define WIDGETFILTRI_H

#include <QAction>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QStyle>
#include <QVBoxLayout>
#include <QWidget>

class WidgetFiltri : public QWidget {
    Q_OBJECT
private:
    QComboBox* tipoAttivita;
    QLineEdit* barraRicerca;
    QMap<QString, QWidget*> widgets;
    bool visibile;
    void mostraFiltri();
public:
    WidgetFiltri(QWidget* parent = nullptr);

    QLineEdit* getBarraRicerca() const;
    QDateTimeEdit* getDataInizio() const;
    QDateTimeEdit* getDataFine() const;
    QComboBox* getTipoAttivita();
};

#endif // WIDGETFILTRI_H
