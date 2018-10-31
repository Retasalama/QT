#include "signalsslots.h"
#include "ui_signalsslots.h"

SignalsSlots::SignalsSlots(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalsSlots)
{
    ui->setupUi(this);
}

SignalsSlots::~SignalsSlots()
{
    delete ui;
}
