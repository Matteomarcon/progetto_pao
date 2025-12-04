#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    QAction* creaAttivita = new QAction(QIcon("../../icone/aggiungi.png"), "Crea una nuova attività (CTRL + N)", this);
    creaAttivita->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    barraStrumenti = addToolBar("barraStrumenti");
    barraStrumenti->addAction(creaAttivita);
}

MainWindow::~MainWindow(){
    for (auto a : listaAttivita) delete a;
    listaAttivita.clear();
}

/*void MainWindow::mostraDettagli(Attivita* attivita) {
    //vistaDettagli->setAttivita(attivita);
    stack.setCurrentIndex(0);

}*/
