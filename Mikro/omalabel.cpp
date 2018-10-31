#include "omalabel.h"

omalabel::omalabel(const QString &text, QWidget * parent ) :
    QLabel(parent)
{

}

void omalabel::mousePressEvent ( QMouseEvent * event )
{
 // lähetetään clicked() signaali kun hiiren nappia on painettu
 emit clicked();
}
