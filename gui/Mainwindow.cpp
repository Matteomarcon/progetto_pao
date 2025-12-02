#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {

}

MainWindow::~MainWindow(){
    for (auto a : listaAttivita) delete a;
    listaAttivita.clear();
}

void MainWindow::mostraDettagli(Attivita* attivita) {
    //vistaDettagli->setAttivita(attivita);
    stack.setCurrentIndex(0);

}
