#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSlider>
#include <QLabel>
#include <QString>
#include <QMultimedia>
#include <QMediaPlayer>
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
    void on_dial_sliderMoved(int position);
    void on_StartButton_clicked();
    void ajastin_laukaistu();
    void on_StopButton_clicked();
    void oveaKlikattu();
    void on_OpenButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *ajastin;
    int aika;
    QLabel *mikronOvi;
    bool kiinni;
    QString viesti;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
