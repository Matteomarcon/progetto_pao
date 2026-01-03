#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    this->setWindowTitle("Gestore Attività Personali");
    this->setWindowIcon(QIcon(":/icone/iconaApp.png"));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    this->resize(screenGeometry.width()/2, screenGeometry.height()/2);
    this->move(screenGeometry.center() - this->rect().center());

    QAction* apriJson = new QAction(QIcon(":/icone/json_apri.png"), "Apri JSON", this);
    apriJson->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* salvaJson = new QAction(QIcon(":/icone/json_salva.png"), "Salva JSON", this);
    salvaJson->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* salvaNuovoJson = new QAction(QIcon(":/icone/json_salva_come.png"), "Salva come JSON", this);
    salvaNuovoJson->setShortcut(QKeySequence(Qt::Key_F12));

    QAction* apriXml = new QAction(QIcon(":/icone/xml_apri.png"), "Apri XML", this);
    apriXml->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));
    QAction* salvaXml = new QAction(QIcon(":/icone/xml_salva.png"), "Salva XML", this);
    salvaXml->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    QAction* salvaNuovoXml = new QAction(QIcon(":/icone/xml_salva_come.png"), "Salva come XML", this);
    salvaNuovoXml->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_F12));

    QAction* creaAttivita = new QAction(QIcon(":/icone/attivita.png"), "Crea attività", this);
    creaAttivita->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    menuApri = menuBar()->addMenu("Apri");
    menuApri->addAction(apriJson);
    menuApri->addAction(apriXml);

    menuSalva = menuBar()->addMenu("Salva");
    menuSalva->addAction(salvaJson);
    menuSalva->addAction(salvaNuovoJson);
    menuSalva->addAction(salvaXml);
    menuSalva->addAction(salvaNuovoXml);

    menuCrea = menuBar()->addMenu("Crea");
    menuCrea->addAction(creaAttivita);

    barraStrumenti = addToolBar("barraStrumenti");
    barraStrumenti->addAction(apriJson);
    barraStrumenti->addAction(salvaJson);
    barraStrumenti->addAction(salvaNuovoJson);
    barraStrumenti->addSeparator();
    barraStrumenti->addAction(apriXml);
    barraStrumenti->addAction(salvaXml);
    barraStrumenti->addAction(salvaNuovoXml);
    barraStrumenti->addSeparator();
    barraStrumenti->addAction(creaAttivita);

    barraStrumenti->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    barraStrumenti->setIconSize(QSize(72, 72));
    for (auto* action : barraStrumenti->actions())
        if (auto* bottone = barraStrumenti->widgetForAction(action))
            bottone->setCursor(Qt::PointingHandCursor);

    stack = new QStackedWidget(this);
    vistaDefault = new VistaDefault(this);
    vistaListaAttivita = new VistaListaAttivita(listaAttivita, this);
    vistaDettagliAttivita = new VistaDettagliAttivita(this);
    vistaCreazioneAttivita = new VistaCreazioneAttivita(this);
    vistaModificaAttivita = new VistaModificaAttivita(this);

    stack->addWidget(vistaDefault);
    stack->addWidget(vistaDettagliAttivita);
    stack->addWidget(vistaCreazioneAttivita);
    stack->addWidget(vistaModificaAttivita);
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
    connect(vistaListaAttivita, &VistaListaAttivita::itemSelezionato, this, &MainWindow::mostraVistaDettagli);
    connect(vistaCreazioneAttivita, &VistaCreazioneAttivita::annulla, this, &MainWindow::mostraVistaDefault);
    connect(vistaCreazioneAttivita, &VistaCreazioneAttivita::salva, this, &MainWindow::salvaCreazione);
    connect(vistaDettagliAttivita, &VistaDettagliAttivita::chiudi, this, &MainWindow::mostraVistaDefault);

    connect(creaAttivita, &QAction::triggered, this, &MainWindow::mostraVistaCreazione);
    connect(salvaJson, &QAction::triggered, this, &MainWindow::salvaJson);

}

MainWindow::~MainWindow(){
    for (auto a : listaAttivita) delete a;
    listaAttivita.clear();
}

void MainWindow::mostraVistaDefault() {
    vistaListaAttivita->deseleziona();
    stack->setCurrentIndex(0);
}

void MainWindow::mostraVistaDettagli(Attivita* a) {
    vistaDettagliAttivita->setAttivita(a);
    stack->setCurrentIndex(1);
}

void MainWindow::mostraVistaCreazione() {
    stack->setCurrentIndex(2);
}

void MainWindow::mostraVistaModifica(Attivita* a) {
    vistaModificaAttivita->setAttivita(a);
    stack->setCurrentIndex(3);
}

void MainWindow::salvaCreazione(Attivita* a) {
    listaAttivita.append(a);
    vistaListaAttivita->aggiornaLista(listaAttivita);
    stack->setCurrentIndex(0);
}

void MainWindow::salvaModifica(Attivita* a) {

}

void MainWindow::salvaJson() { //SalvaComeNuovoJson da rinominare
    //if (!unsavedChanges) return;
    pathJson = QFileDialog::getSaveFileName(this, "Crea nuovo file JSON", "./",
                                                "JSON files *.json");
    if (pathJson.isEmpty()) return;
    if (!pathJson.endsWith(".json", Qt::CaseInsensitive)) pathJson += ".json";

    GestoreJson gestoreJson(pathJson);
    gestoreJson.setListaAttivita(listaAttivita);
    gestoreJson.salvaJSON();

    //unsavedChanges = false;
}
