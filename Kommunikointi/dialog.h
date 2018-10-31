#ifndef DIALOG_H
#define DIALOG_H
#include <QString>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void send();

private:
    Ui::Dialog *ui;
    QString viesti;

signals:
    void NappiPainettu(QString);
};

#endif // DIALOG_H
