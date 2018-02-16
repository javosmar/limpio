#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

QString Dialog2::pedido() const
{
    return texto;
}

void Dialog2::on_buttonBox_accepted()
{
    texto = ui->lineEditenviar->text();
    emit senal();
}
