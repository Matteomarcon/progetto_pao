#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    QAction* creaAttivita = new QAction(QIcon("../../icone/aggiungi.png"), "Crea una nuova attività (CTRL + N)", this);
    creaAttivita->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    barraStrumenti = addToolBar("barraStrumenti");
    barraStrumenti->addAction(creaAttivita);

    stack = new QStackedWidget(this);
    vistaListaAttivita = new VistaListaAttivita(listaAttivita, this);
    vistaCreazioneAttivita = new VistaCreazioneAttivita(this);
    vistaVuota = new QWidget(this);

    stack->addWidget(vistaCreazioneAttivita);
    stack->addWidget(vistaVuota);
    stack->setCurrentIndex(0);

    QSplitter* divisore = new QSplitter(Qt::Horizontal, this);

    divisore->setStyleSheet(
        "QSplitter::handle {"
        "background-color: white;"
        "width: 20px;"
        "}"
    );

    QWidget* colonnaSinistra = new QWidget();
    QVBoxLayout* layoutColonnaSinistra = new QVBoxLayout(colonnaSinistra);

    layoutColonnaSinistra->setSpacing(0);
    layoutColonnaSinistra->setContentsMargins(0, 0, 0, 0);
    layoutColonnaSinistra->addWidget(vistaListaAttivita);

    divisore->addWidget(colonnaSinistra);
    divisore->addWidget(stack);
    divisore->setStretchFactor(0,1);
    divisore->setStretchFactor(1,2);

    setCentralWidget(divisore);
}

MainWindow::~MainWindow(){
    for (auto a : listaAttivita) delete a;
    listaAttivita.clear();
}

/*void MainWindow::mostraDettagli(Attivita* attivita) {
    //vistaDettagli->setAttivita(attivita);
    stack.setCurrentIndex(0);

}*/
