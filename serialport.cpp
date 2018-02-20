#include "serialport.h"

serialPort::serialPort()
{

}

void serialPort::Serial_Conf(QString com)
{
    serial.setPortName(com);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
}

bool serialPort::Serial_Conect()
{
    bool estado_serial = false;
    if((serial.open(QIODevice::ReadWrite)))
    {
        estado_serial = true;
        serial.write("A");
    }
    else{
        Serial_Error();
    }
    return estado_serial;
}

bool serialPort::Serial_Desconect()
{
    serial.write("X");
    serial.waitForBytesWritten(30);
    serial.close();
    bool estado_serial = false;
    return estado_serial;
}

void serialPort::Serial_Error()
{
    QMessageBox error;
    error.setText("Verifique la conexión de la placa.");
    error.setIcon(QMessageBox::Warning);
    error.exec();
}

void serialPort::Serial_Pedir()
{

}
