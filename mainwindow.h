#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog2.h>
#include <dbmanager.h>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void ejecutarNuevo();
    void actualizarLista();
    void on_actionNew_Player_triggered();
    void ejecutarNuevoJugador();
    void setFalse();
    void setTrue();

    void on_pushButtonescribir_clicked();

    void on_pushButtoncerrar_clicked();

private:
    Ui::MainWindow *ui;
    Dialog2 *ventana;
    DbManager *db;
    QString path, nombre;
};

#endif // MAINWINDOW_H
