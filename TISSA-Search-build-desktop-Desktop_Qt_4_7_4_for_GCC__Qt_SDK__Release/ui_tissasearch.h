/********************************************************************************
** Form generated from reading UI file 'tissasearch.ui'
**
** Created: Fri Nov 11 22:59:17 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TISSASEARCH_H
#define UI_TISSASEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TISSASearch
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *TISSASearch)
    {
        if (TISSASearch->objectName().isEmpty())
            TISSASearch->setObjectName(QString::fromUtf8("TISSASearch"));
        TISSASearch->resize(446, 100);
        TISSASearch->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(TISSASearch);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TISSASearch);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(TISSASearch);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(TISSASearch);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(TISSASearch);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setAutoDefault(false);
        pushButton_2->setDefault(true);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TISSASearch);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(TISSASearch);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        pushButton_3 = new QPushButton(TISSASearch);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(TISSASearch);

        QMetaObject::connectSlotsByName(TISSASearch);
    } // setupUi

    void retranslateUi(QDialog *TISSASearch)
    {
        TISSASearch->setWindowTitle(QApplication::translate("TISSASearch", "TISSA-Search", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TISSASearch", "File:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TISSASearch", "Browse", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("TISSASearch", "Load", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TISSASearch", "Find:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("TISSASearch", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TISSASearch: public Ui_TISSASearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TISSASEARCH_H
