#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog2.h>
#include <dbmanager.h>
#include <QFileDialog>

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
    void on_pushButtonnuevo_clicked();
    void ejecutarNuevo();

private:
    Ui::MainWindow *ui;
    Dialog2 *ventana;
    DbManager *db;
};

#endif // MAINWINDOW_H
