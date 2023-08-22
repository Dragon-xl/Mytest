#include "welcomewg.h"
#include<QPainter>
WelcomeWg::WelcomeWg(QWidget *parent)
    : QWidget{parent}
{

}

void WelcomeWg::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix(":/src/undraw_welcome_cats_thqn.png");
    painter.drawPixmap(0,0,width(),height(),pix);


}
