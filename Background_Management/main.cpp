#include "mainwindow.h"
#include<QDialog>
#include <QApplication>
#include"dblogin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBLogin login;

    login.show();
    if(QDialog::Accepted)
   {
        MainWindow w;
        w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint);
        w.show();
   }
    else if(QDialog::Rejected)
    {
       login.close();
    }

    return a.exec();
}
