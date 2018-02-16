#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    QString pedido() const;

signals:
    void senal();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog2 *ui;
    QString texto;
};

#endif // DIALOG2_H
