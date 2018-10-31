#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("com6");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
   // serial->setFlowControl(QSerialPort::NoFlowControl);
     serial->setFlowControl(QSerialPort::HardwareControl);
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << serial->portName();
    }
    else
    {
        qDebug() << "Portin avaaminen ei onnistunut!";
    }
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
    }

mainwindow::~mainwindow()
{
    serial->close();
    delete ui;

}
void mainwindow::serialReceived()
{

    QString hexNum,cardSerialNumber;
    char data[9], temp[9];
    int bytesRead;
    bytesRead = serial->read(data, 8);
    data[bytesRead] = '\0';
    if (bytesRead>0)
    {
        for (int i=0;i<=7;i++)
        {
            sprintf(temp,"%08X", data[i]);
            hexNum = temp;
            cardSerialNumber = cardSerialNumber + hexNum.right(2);
        }
        qDebug() << "Kortin numero: " << cardSerialNumber << endl;
        ui->label->setText(cardSerialNumber);
    }
    else
        qDebug()<<"Virhe korttia luettaessa!";
}


void mainwindow::on_pushButton_clicked()
{
    serial->write("U");
  //  msleep(500);
}
