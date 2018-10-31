#ifndef OMALABEL_H
#define OMALABEL_H

#include <QWidget>
#include <QLabel>
#include <QObject>


class omalabel : public QLabel
{
    Q_OBJECT
public:
    omalabel( const QString & text, QWidget * parent );
     ~omalabel(){}

    // signaali joka lähetetään kun hiirtä on klikattu labelin alueen sisällä
signals:
    void clicked();

    // QWidgetiltä peritty funktio joka täytyy nyt ylikirjoittaa
protected:
     void mousePressEvent ( QMouseEvent * event ) ;
};

#endif // OMALABEL_H
