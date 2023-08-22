#include "dblogin.h"
#include<QMessageBox>
#include "ui_dblogin.h"
#include"jsonparse.h"
#include"databasefuc.h"
DBLogin::DBLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBLogin)
{

    ui->setupUi(this);
    this->setWindowTitle("连接数据库");

    ui->lineEdit->setText(json.getHostname());//1
    ui->lineEdit_2->setText(json.getDBport());
    ui->lineEdit_3->setText(json.getDBname());//2
    ui->lineEdit_4->setText(json.getUsername());//3
    ui->lineEdit_5->setText(json.getPwd());//4
}

DBLogin::~DBLogin()
{
    delete ui;
}

void DBLogin::on_pushButton_dbtest_clicked()
{
    DataBaseFuc db;
    bool bl = db.openDataBase(ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_2->text().toInt(),ui->lineEdit->text(),ui->lineEdit_3->text());
    if(bl == false)
    {
        QMessageBox::critical(this,"错误","连接失败");
    }
    else {
        QMessageBox::information(this,"成功","数据库连接成功");
       }
}


void DBLogin::on_pushButton_confrim_clicked()
{
       on_pushButton_dbtest_clicked();
       json.writeJsonFile(ui->lineEdit->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_2->text());
       accept();

}


void DBLogin::on_pushButton_cancel_clicked()
{
       reject();
}

