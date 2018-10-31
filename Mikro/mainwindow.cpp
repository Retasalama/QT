#include "mainwindow.h"
#include "omalabel.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QPixmap>
#include <QMultimedia>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mikronOvi = new omalabel("",this);
    QPixmap ovi_kiinni_kuva("/Users/tanja/Koulujutut/QT/Mikro/mikrokiinni.jpg");
    mikronOvi->setPixmap(ovi_kiinni_kuva);
    mikronOvi->resize(200,200);
    mikronOvi->move(10,10);
    QPixmap skaalattu_kuva = ovi_kiinni_kuva.scaled(mikronOvi->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    mikronOvi->setPixmap(skaalattu_kuva);
    kiinni = true;
    connect(mikronOvi,SIGNAL(clicked()), this, SLOT(oveaKlikattu()));

    ajastin = new QTimer(this);
    ajastin->setInterval(aika);
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("/Users/tanja/Koulujutut/QT/Mikro/mikro.mp3"));

    connect(ajastin, SIGNAL(timeout()), this,SLOT(ajastin_laukaistu()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ajastin;
    delete mikronOvi;
    delete player;
}

void MainWindow::on_dial_sliderMoved(int position)
{
    ui->lcdNumber->display(position);
    aika = position;
}

void MainWindow::on_StartButton_clicked()
{
    if(kiinni == true && aika > 0){
        ajastin->setInterval(1000);
        ajastin->start();
    }

}

void MainWindow::ajastin_laukaistu()
{
    aika--;
    ui->lcdNumber->display(aika);
    ui->dial->setValue(aika);
    if(aika == 0)
    {
        ajastin->stop();
        player->play();
    }
}

void MainWindow::on_StopButton_clicked()
{
    if(ajastin->isActive() == true)
    {
        ajastin->stop();
    }
    else
    {
        ui->lcdNumber->display(0);
        ui->dial->setValue(0);
        aika = 0;

    }
}
void MainWindow::oveaKlikattu()
{
    if(kiinni == true){
        QPixmap ovi_auki_kuva("/Users/tanja/Koulujutut/QT/Mikro/mikroauki.jpg");
        mikronOvi->setPixmap(ovi_auki_kuva);
        QPixmap skaalattu_kuva = ovi_auki_kuva.scaled(mikronOvi->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        mikronOvi->setPixmap(skaalattu_kuva);
        kiinni = false;
        ajastin->stop();
    }
    else{
        QPixmap ovi_kiinni_kuva("/Users/tanja/Koulujutut/QT/Mikro/mikrokiinni.jpg");
        mikronOvi->setPixmap(ovi_kiinni_kuva);
        QPixmap skaalattu_kuva = ovi_kiinni_kuva.scaled(mikronOvi->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        mikronOvi->setPixmap(skaalattu_kuva);
        kiinni = true;
    }


}


void MainWindow::on_OpenButton_clicked()
{
    if(kiinni == true)
    {
       emit oveaKlikattu();
    }


}
