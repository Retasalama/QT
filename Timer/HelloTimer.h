#ifndef TIMER_H
#define TIMER_H
/*** helloTimer.h ***/
#include <qpushbutton.h>
#include <qtimer.h>
class HelloTimer : public QPushButton {
Q_OBJECT
private:
QTimer *timer;
unsigned int timeLeft;
public:
HelloTimer() {
timeLeft = 10;
timer = new QTimer(this);
this->connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
this->connect(this, SIGNAL(clicked()), this, SIGNAL(helloQuits()));
setWindowTitle(tr("Hello World!"));
resize(200, 60);
updateTime();
timer->setInterval(1000);
timer->start();
}
private slots:
void updateTime() {
if (!(--timeLeft))
emit helloQuits();
this->setText(tr("Quit") + "..." + QString::number(timeLeft));
}
signals:
void helloQuits();
};
#endif // TIMER_H
