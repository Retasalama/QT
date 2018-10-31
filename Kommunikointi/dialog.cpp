#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    viesti = "Viesti MainWindowlle";
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(send()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{


}

void Dialog::send()
{
    emit NappiPainettu(viesti);
}

