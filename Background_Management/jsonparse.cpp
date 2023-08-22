#include "jsonparse.h"
#include<QFile>
#include<QFileInfo>
#include<QJsonDocument>
#include<QByteArray>
#include<QJsonObject>
JsonParse::JsonParse(QObject *parent)
    : QObject{parent}
{

}

JsonParse::~JsonParse()
{

}

QJsonDocument JsonParse::openJsonFile(QString filename)
{
    QFileInfo info(filename);
    if(info.exists())
    {
        QFile file(filename);
       bool b =  file.open(QIODevice::ReadWrite);
        if(!b)
       {
           qDebug()<<"文件打开失败";
           return QJsonDocument();
       }
       QByteArray ba = file.readAll();
       QJsonDocument json =  QJsonDocument::fromJson(ba);
       return json;

    }
    else
    {
       qDebug()<<"json文件不存在";
        return QJsonDocument();
    }
}

QString JsonParse::getHostname()
{
    return readJson("hostname");
}

QString JsonParse::getDBname()
{
    return readJson("dbname");
}

QString JsonParse::getUsername()
{
    return readJson("dbuser");
}

QString JsonParse::getPwd()
{
    return readJson("dbpasswd");
}

QString JsonParse::getDBport()
{
    return readJson("dbport");
}

void JsonParse::writeJsonFile(QString hostname, QString dbname, QString username, QString passwd, QString dbport)
{
    QJsonObject jo;
    jo.insert("hostname",hostname);
    jo.insert("dbname",dbname);
    jo.insert("dbuser",username);
    jo.insert("dbpasswd",passwd);
    jo.insert("dbpot",dbport);

    QFile file(cfg);
    file.open(QFile::WriteOnly);
    QJsonDocument doc(jo);
    QByteArray ba = doc.toJson();
    file.write(ba);
    file.close();
}

QString JsonParse::readJson(QString key, QString filename)
{
    QJsonDocument json = openJsonFile(filename);
    if(json.isNull())
    {
        return QString();
    }
    if(json.isObject())
    {
        QJsonObject jo = json.object();
        QString value = jo.value(key).toString();
        return value;
    }
    return QString();
}




