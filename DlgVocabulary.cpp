#include "DlgVocabulary.h"
#include "ui_DlgVocabulary.h"
#include <QInputDialog>

DlgVocabulary *DlgVocabulary::dialog = 0;

DlgVocabulary::DlgVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgVocabulary)
{
    ui->setupUi(this);
    this->setWindowTitle("Hash table");
}

DlgVocabulary::~DlgVocabulary()
{
    delete ui;
}

void DlgVocabulary::showVocabulary(QWidget *parent, CountWord *countWord)
{
    if(!countWord) throw QString("Without text.");
    if(dialog)
        dialog->setParent(parent);
    else
        dialog = new DlgVocabulary(parent);

    /*preenchimento do grid*/
    int column;
    StringData *strData = countWord->getWordCount(column);
    QStringList hearder;


    dialog->ui->tableWidget->clear();
    dialog->ui->tableWidget->setColumnCount(column);
    dialog->ui->tableWidget->setRowCount(1);
    for(int i = 1; i <= column; i++)
    {
        hearder << QString::fromStdString(strData[column - i].getStr());
        dialog->ui->tableWidget->setItem(0, i - 1, new QTableWidgetItem(QString::number(strData[column - i].getCount())));
    }
    dialog->ui->tableWidget->setHorizontalHeaderLabels(hearder);
    dialog->setModal(false);
    dialog->show();
}

void DlgVocabulary::closeVocabulary()
{
    dialog->close();
}
