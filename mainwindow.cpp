#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("GPSport");
    ventana = new Dialog2(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonnuevo_clicked()
{
    connect(ventana,SIGNAL(senal()),this,SLOT(ejecutarNuevo()));
    ventana->setModal(true);
    ventana->setWindowTitle("Nuevo Jugador");
    ventana->show();
}

void MainWindow::ejecutarNuevo()
{
    QString nombre;
    nombre = ventana->pedido();
    QString path = QFileDialog::getSaveFileName(
                this,
                "GPSport - Nueva base de datos",
                "/Users/javos/Desktop/casa",
                "Databases (*.sqlite);;All Files (*.*)");
    db = new DbManager(path);
}
