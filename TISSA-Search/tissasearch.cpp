#include "tissasearch.h"
#include "ui_tissasearch.h"

TISSASearch::TISSASearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TISSASearch)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setDefault(true);
    connect(ui->lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
    connect(ui->lineEdit_2, SIGNAL(textChanged(const QString &)), this, SLOT(enableSearchButton(const QString &)));
}

TISSASearch::~TISSASearch()
{
    delete ui;
}

void TISSASearch::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Text file (*.txt)"));
    ui->lineEdit->setText(filePath);
    ui->pushButton->setDefault(false);
    ui->pushButton_2->setDefault(true);
    ui->pushButton_2->setFocus();
}

void TISSASearch::on_pushButton_2_clicked()
{
    ui->lineEdit_2->clear();
    pathName = ui->lineEdit->text();
    int l_num = 1;

    // Input read from the file.

    QFile inFile(ui->lineEdit->text());
    if (!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "File could not be opened");
        return;
    }
    QTextStream tStream(&inFile);
    QString sln = tStream.readLine();
    while (!sln.isNull())
    {
        QStringList sList = sln.split(" ");
        QStringList::Iterator itr;
        for (itr = sList.begin(); itr != sList.end(); ++itr)
        {
            QString nak = *itr;
            string sw = nak.toStdString();
            sTree.Insert(sw, l_num);
        }
        sln.clear();
        sln = tStream.readLine();
        l_num++;
    }
    QMessageBox::information(this, "Loading", "Loading complete");
    ui->pushButton_2->setDefault(false);
    ui->pushButton_3->setDefault(true);
    ui->lineEdit_2->setFocus();
}


void TISSASearch::on_pushButton_3_clicked()
{
    searchWord = ui->lineEdit_2->text();
    string str = searchWord.toStdString();
    //QMessageBox::information(this, "Word", searchWord);
    list<int> presentList = sTree.IsPresent(str);
    if (!presentList.empty())
    {
        QString res;
        while (!presentList.empty())
        {
                res.append(QString::number(presentList.front()));
                res.append(" ");
                presentList.pop_front();
        }
        QMessageBox::information(this, "Search Result", searchWord + " found at line(s) " + res);
    }
    else
    {
        QMessageBox::information(this, "Search Result", searchWord + " not found");
    }
}

void TISSASearch::enableFindButton(const QString &text)
{
    ui->pushButton_2->setEnabled(!text.isEmpty());
}

void TISSASearch::enableSearchButton(const QString &text)
{
    ui->pushButton_3->setEnabled(!text.isEmpty());
}
