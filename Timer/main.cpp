/*** main.cpp ***/
#include <QWidget>
#include <QApplication>
#include "HelloTimer.h"
int main(int argc, char **argv)
{
QApplication app(argc, argv);
HelloTimer hello;
QObject::connect(&hello, SIGNAL(helloQuits()), &app, SLOT(quit()));
hello.show();
return app.exec();
}
