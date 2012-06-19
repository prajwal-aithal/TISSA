/********************************************************************************
** Form generated from reading UI file 'tissadictionary.ui'
**
** Created: Sat Nov 12 10:50:39 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TISSADICTIONARY_H
#define UI_TISSADICTIONARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TISSADictionary
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *TISSADictionary)
    {
        if (TISSADictionary->objectName().isEmpty())
            TISSADictionary->setObjectName(QString::fromUtf8("TISSADictionary"));
        TISSADictionary->resize(432, 45);
        gridLayout = new QGridLayout(TISSADictionary);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TISSADictionary);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(TISSADictionary);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(TISSADictionary);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        retranslateUi(TISSADictionary);

        QMetaObject::connectSlotsByName(TISSADictionary);
    } // setupUi

    void retranslateUi(QDialog *TISSADictionary)
    {
        TISSADictionary->setWindowTitle(QApplication::translate("TISSADictionary", "TISSA - Dictionary", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TISSADictionary", "Find:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TISSADictionary", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TISSADictionary: public Ui_TISSADictionary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TISSADICTIONARY_H
