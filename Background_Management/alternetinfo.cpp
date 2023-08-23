#include "alternetinfo.h"
#include "ui_alternetinfo.h"
#include"time.h"
#include"databasefuc.h"
AlterNetInfo::AlterNetInfo(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlterNetInfo)
{
    m_id=id;
    ui->setupUi(this);
    DataBaseFuc db ;
    QVector<QVariantList> list =  db.selectDataBase("SECNODE","id = "+id);
    QVariantList mylist = list.at(0);
    ui->lineEdit->setText(mylist.at(0).toString());
    ui->lineEdit_2->setText(mylist.at(1).toString());
    ui->lineEdit_3->setText(mylist.at(2).toString());
    ui->lineEdit_4->setText(mylist.at(4).toString());
    ui->lineEdit_5->setText(mylist.at(5).toString());
}

AlterNetInfo::~AlterNetInfo()
{
    delete ui;
}

void AlterNetInfo::on_pushButton_re_clicked()
{
    srand(time(NULL));
    QString str;
    for(int i =0;i<6;i++)
    {
         str +=QString::number(rand()%10);
    }
    ui->lineEdit_4->setText(str);
}


void AlterNetInfo::on_pushButton_2_clicked()
{
    DataBaseFuc db;
    QStringList field ;
    field<<"id"<<"name"<<"nodedesc";
        //db.updateDatabase("SECNODE",field);
}


void AlterNetInfo::on_pushButton_3_clicked()
{
    close();
}

