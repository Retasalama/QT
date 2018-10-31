#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSerialPort>
#include <QMainWindow>



namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();
private slots:
    void serialReceived();
    void on_pushButton_clicked();

private:
    Ui::mainwindow *ui;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
