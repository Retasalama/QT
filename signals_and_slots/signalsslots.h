#ifndef SIGNALSSLOTS_H
#define SIGNALSSLOTS_H

#include <QMainWindow>

namespace Ui {
class SignalsSlots;
}

class SignalsSlots : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalsSlots(QWidget *parent = 0);
    ~SignalsSlots();

private:
    Ui::SignalsSlots *ui;
};

#endif // SIGNALSSLOTS_H
