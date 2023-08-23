#ifndef ALTERNETINFO_H
#define ALTERNETINFO_H

#include <QDialog>

namespace Ui {
class AlterNetInfo;
}

class AlterNetInfo : public QDialog
{
    Q_OBJECT

public:
     AlterNetInfo(QString id,QWidget *parent = nullptr);
    ~AlterNetInfo();

private slots:
    void on_pushButton_re_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AlterNetInfo *ui;
    QString m_id;
};

#endif // ALTERNETINFO_H
