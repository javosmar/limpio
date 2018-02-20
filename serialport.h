#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QMessageBox>
#include <iostream>

class serialPort
{
public:
    serialPort();
    void Serial_Conf(QString com);
    bool Serial_Conect();
    bool Serial_Desconect();
    void Serial_Error();
    void Serial_Pedir();

private:
    QSerialPort serial;
};

#endif // SERIALPORT_H
