#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qApp->exit();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->label->isVisible())
    {ui->pushButton_2->setText("Teksti takas");
        ui->label->setVisible(false);
    }
    else
    {ui->pushButton_2->setText("Teksti pois");
        ui->label->setVisible(true);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}
