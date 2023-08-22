#include "databasefuc.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QMessageBox>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QDateTime>
DataBaseFuc::DataBaseFuc(QObject *parent)
    : QObject{parent}
{

}

bool DataBaseFuc::openDataBase(QString user, QString pwd, int port, QString hostname,QString dbname)
{
    if(user==NULL||pwd==NULL||port <= 0 ||hostname==NULL)
    {
        return false;
    }
    QSqlDatabase db =QSqlDatabase::database();
    if(db.isOpen())
    {
        return true;
    }
    db = QSqlDatabase::addDatabase("QCI");
    db.setHostName(hostname);
    db.setUserName(user);
    db.setPassword(pwd);
    db.setPort(port);
    db.setDatabaseName(dbname);
    if(db.open())
    {
        QMessageBox::critical(NULL,"error",db.lastError().text());
        return false;
    }
    return true;

}

void DataBaseFuc::closeDateBase()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();

}

QVector<QVariantList> DataBaseFuc::selectDataBase(QString tables, QString filter)
{
    QString sql;
    QVector<QVariantList> list;
    list.clear();
    if(filter.isEmpty())
    {
        sql = QString("select * from %1").arg(tables);
    }
    else
    {
        sql = QString("select * from %1 where %2").arg(tables).arg(filter);
    }
    qDebug()<<"sql:"<<sql;
    QSqlQuery query;
    if(query.exec(sql))
    {
        while(query.next())
        {
            QVariantList sublist;
            QSqlRecord rd = query.record();
            for(int i =0;i<rd.count();i++)
            {
                sublist.append(rd.value(i));
            }
            list.append(sublist);
        }

    }
    else
    {
        qDebug()<< "select failed";
    }
    return list;

}

bool DataBaseFuc::insertDatabase(QString table, QStringList fields, QVariantList values)
{
    QStringList vallist;
    QString sql;
    QString myfield =fields.join(",");
    for(int i =0;i<values.size();i++)
    {
        QString str;
        if(values.at(i).type() == QVariant::String)
        {
            str = QString("'"+values.at(i).toString()+"'");
        }
        else if(values.at(i).type()== QVariant::DateTime)
        {
             str = QString("to_data('%1','yyyy-mm-dd hh24:mi:ss')").arg(values.at(i).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        }
        else
        {
            str= QString(values.at(i).toString());
        }
        vallist.append(str);
    }
    QString myvalist = vallist.join(",");
    sql = QString("insert into %1(%2) values (%3)").arg(table).arg(myfield).arg(myvalist);
    qDebug()<<"sql:"<<sql;
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    if(query.exec(sql))
    {
        db.commit();
        return true;
    }
    else
    {
        db.rollback();
        qDebug()<<"insert failed";
        return false;
    }

}

bool DataBaseFuc::updateDatabase(QString table, QStringList fields, QVariantList values, QString filter)
{
    QStringList list;
    QString str;
    QString sql;
    for(int i =0;i<fields.size();i++)
    {
        QString str;
        if(values.at(i).type() == QVariant::String)
        {
            str = QString("%1='%2'").arg(fields.at(i)).arg(values.at(i).toString());
        }
        else if(values.at(i).type() == QVariant::DateTime)
        {
            str = QString("%1=to_data('%2','yyyy-mm-dd hh24:mi:ss')").arg(fields.at(i)).arg(values.at(i).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
        else
        {
            str =QString("%1=%2").arg(fields.at(i)).arg(values.at(i).toInt());
        }
        list.append(str);
    }
    str = list.join(",");
    sql = QString("update %1 set %2 where %3").arg(table).arg(str).arg(filter);
    qDebug()<<"sql:"<<sql;
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    if(query.exec(sql))
    {
        db.commit();
        return true;
    }
    else
    {
        db.rollback();
        qDebug()<<"update failed";
        return false;
    }

}

bool DataBaseFuc::delDatabase(QString table, QString filter)
{
    QString sql;
    sql = QString("delete from %1 where %2").arg(table).arg(filter);
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    QSqlQuery query;
    if(query.exec(sql))
    {
        db.commit();
        return true;
    }
    else
    {
        db.rollback();
        qDebug()<<"delete failed";
        return false;
    }

}




















