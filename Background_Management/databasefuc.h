#ifndef DATABASEFUC_H
#define DATABASEFUC_H

#include <QObject>

class DataBaseFuc : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseFuc(QObject *parent = nullptr);
    bool openDataBase(QString user ,QString pwd,int port,QString hostname,QString dbname);
    void closeDateBase();
    QVector<QVariantList> selectDataBase(QString tables,QString filter =QString());
    bool insertDatabase(QString table,QStringList fields,QVariantList values);
    bool updateDatabase(QString table,QStringList fields,QVariantList values,QString filter);
    bool delDatabase(QString table,QString filter);
signals:

};

#endif // DATABASEFUC_H
