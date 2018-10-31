#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //luo dialogi-olio
    dialog_olio = new Dialog(this);
    dialog_olio->show();

    connect(dialog_olio,SIGNAL(NappiPainettu(QString)),this,SLOT(SignaalinVastaanotto(QString)));
}

MainWindow::~MainWindow()
{

    delete dialog_olio;
    delete ui;
}

//tänne slotti jonka esittely headerissa, ottaa stringin vastaan ja mitä sille tehdään
void MainWindow::SignaalinVastaanotto(QString viesti)
{
    ui->lineEdit->setText(viesti);
}


