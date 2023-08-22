#ifndef DBLOGIN_H
#define DBLOGIN_H
#include"jsonparse.h"
#include <QDialog>

namespace Ui {
class DBLogin;
}

class DBLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DBLogin(QWidget *parent = nullptr);
    ~DBLogin();

private slots:
    void on_pushButton_dbtest_clicked();

    void on_pushButton_confrim_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DBLogin *ui;
    JsonParse json;
};

#endif // DBLOGIN_H
