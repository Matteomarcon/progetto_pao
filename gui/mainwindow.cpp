#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    this->setWindowTitle("Gestore Attività Personali");
    this->setWindowIcon(QIcon("../../icone/iconaApp.png"));

    //Sistemare icone, shortcut, ordine della barra degli strumenti

    QAction* creaAttivita = new QAction(QIcon("../../icone/aggiungi.png"), "Crea una nuova attività (CTRL + N)", this);
    creaAttivita->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    QLabel* labelJson = new QLabel("Json:", this);
    QAction* apriJson = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    apriJson->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));
    QAction* salvaJson = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    salvaJson->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));
    QAction* salvaNuovoJson = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    salvaNuovoJson->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));

    QLabel* labelXml = new QLabel("Xml:", this);
    QAction* apriXml = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    apriXml->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));
    QAction* salvaXml = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    salvaXml->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));
    QAction* salvaNuovoXml = new QAction(QIcon("../../icone/apriJson.png"), "Crea una nuova attività (CTRL + N)", this);
    salvaNuovoXml->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_J));

    barraStrumenti = addToolBar("barraStrumenti");
    barraStrumenti->addAction(creaAttivita);
    barraStrumenti->addWidget(labelJson);
    barraStrumenti->addAction(apriJson);
    barraStrumenti->addAction(salvaJson);
    barraStrumenti->addAction(salvaNuovoJson);
    barraStrumenti->addWidget(labelXml);
    barraStrumenti->addAction(apriXml);
    barraStrumenti->addAction(salvaXml);
    barraStrumenti->addAction(salvaNuovoXml);

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
