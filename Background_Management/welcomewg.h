#ifndef WELCOMEWG_H
#define WELCOMEWG_H

#include <QWidget>

class WelcomeWg : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWg(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *ev);

signals:

};

#endif // WELCOMEWG_H
