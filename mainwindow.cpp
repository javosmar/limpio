#include "mainwindow.h"
#include "ui_mainwindow.h"

bool ok;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("GPSport");
    ventana = new Dialog2(this);
    serial = new serialPort();
    setFalse();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    path.clear();
    path = QFileDialog::getSaveFileName(
                this,
                "GPSport - Nueva base de datos",
                "/Users/javos/Desktop/",
                "Databases (*.sqlite);;All Files (*.*)");
    if(!path.isNull())
        ejecutarNuevo();
}

void MainWindow::ejecutarNuevo()
{
    db = new DbManager(path);
    if(db->isOpen()){
        setTrue();
        QString titulo;
        titulo.append("GPSport - ");
        titulo.append(path);
        this->setWindowTitle(titulo);
        actualizarLista();
    }
}

void MainWindow::actualizarLista()
{
    ui->comboBoxlista->clear();
    QStringList lista;
    lista = db->obtenerLista();
    foreach (const QString &str, lista)
        ui->comboBoxlista->insertItem(0,str);
}

void MainWindow::on_actionNew_Player_triggered()
{
    connect(ventana,SIGNAL(senal()),this,SLOT(ejecutarNuevoJugador()));
    ventana->setModal(true);
    ventana->setWindowTitle("Nuevo Jugador");
    ventana->show();
}

void MainWindow::ejecutarNuevoJugador()
{
    nombre = ventana->pedido();
    if(db->createTable(nombre))
        ui->pushButtonescribir->setEnabled(true);
}

void MainWindow::setFalse()
{
    ui->actionNew->setEnabled(true);
    ui->actionNew_Player->setEnabled(false);
    ui->pushButtonescribir->setEnabled(false);
}

void MainWindow::setTrue()
{
    ui->actionNew_Player->setEnabled(true);
}

void MainWindow::on_pushButtonescribir_clicked()
{
    DbManager::DataBlock currentData;
    currentData.validez = ui->lineEditvalidez->text();
    currentData.latitud = ui->lineEditlatitud->text().toInt(&ok);
    currentData.longitud = ui->lineEditlongitud->text().toInt(&ok);
    currentData.velocidad = ui->lineEditvelocidad->text().toInt(&ok);
    currentData.pulsacion = ui->lineEditpulsacion->text();
    db->addData(nombre,currentData);
}

void MainWindow::on_pushButtoncerrar_clicked()
{
    db->~DbManager();
}
