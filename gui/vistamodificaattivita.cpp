#include "vistamodificaattivita.h"
#include <QVBoxLayout>

VistaModificaAttivita::VistaModificaAttivita(QWidget *parent)
    : QWidget{parent}
{}

void VistaModificaAttivita::setAttivita(Attivita*) {

}

void VistaModificaAttivita::pulisciLayout(QLayout* layout) {
    if (!layout) return;
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* subLayout = item->layout()) {
            pulisciLayout(subLayout);
            delete subLayout;
        }
        delete item;
    }
}
