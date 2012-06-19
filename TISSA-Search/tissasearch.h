#ifndef TISSASEARCH_H
#define TISSASEARCH_H

#include <QDialog>
#include <QTextStream>
#include <QtCore>
#include <QtGui>
#include "suffix-tree.h"

namespace Ui {
    class TISSASearch;
}

class TISSASearch : public QDialog
{
    Q_OBJECT

public:
    explicit TISSASearch(QWidget *parent = 0);
    ~TISSASearch();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void enableFindButton(const QString &text);

    void enableSearchButton(const QString &text);

private:
    Ui::TISSASearch *ui;
    QString pathName;
    QString searchWord;
    suffix_tree sTree;
    QString filePath;
};

#endif // TISSASEARCH_H
