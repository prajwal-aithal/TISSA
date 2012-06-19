#ifndef TISSADICTIONARY_H
#define TISSADICTIONARY_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "dictionary-compressed.h"

namespace Ui {
    class TISSADictionary;
}

class TISSADictionary : public QDialog
{
    Q_OBJECT

public:
    explicit TISSADictionary(QWidget *parent = 0);
    ~TISSADictionary();

private slots:
    void on_pushButton_clicked();

    void enableSearch(const QString &text);

private:
    Ui::TISSADictionary *ui;
    Dictionary dict;
    QString usrQry;
};

#endif // TISSADICTIONARY_H
