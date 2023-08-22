#ifndef JSONPARSE_H
#define JSONPARSE_H

#include <QObject>
const QString cfg ="dbconfig.json";
class JsonParse : public QObject
{
    Q_OBJECT
public:
    explicit JsonParse(QObject *parent = nullptr);
    ~JsonParse();
    QJsonDocument openJsonFile(QString filename = cfg);
    QString getHostname();
    QString getDBname();
    QString getUsername();
    QString getPwd();
    QString getDBport();
    void writeJsonFile(QString hostname,QString dbname,QString username,QString passwd,QString dbport);

private:
    QString readJson(QString key,QString filename = cfg);

signals:

};

#endif // JSONPARSE_H
