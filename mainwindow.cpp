#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "DlgVocabulary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Vocabulation");
    countWord = 0;

    lineEditFind = new QLineEdit(this);
    labelStatus = new QLabel(this);
    ui->statusBar->addPermanentWidget(lineEditFind, 1);
    ui->statusBar->addPermanentWidget(labelStatus, 1);
    connect(lineEditFind, SIGNAL(returnPressed()), this, SLOT(fineWord()));
    connect(lineEditFind, SIGNAL(cursorPositionChanged(int,int)), SLOT(clickLineFind(int, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    if(countWord) delete countWord;
    ui->textEdit->setText("");

    QString end = QFileDialog::getOpenFileName(this, "Abrir...", "", "Arquivo de texto(*.txt)");
    try{
        countWord = new CountWord(end.toStdString());
        ui->textEdit->setText(QString::fromStdString(countWord->getTextOrg()));
    } catch (string &e) {
        ui->textEdit->setText(QString::fromStdString(e));
        countWord = __null;
    }
}

void MainWindow::on_actionLocalizar_triggered()
{
    lineEditFind->setFocus();
    if(countWord) ui->textEdit->setText(QString::fromStdString(' ' + countWord->getText()));
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionOriginal_triggered()
{
    if(countWord) ui->textEdit->setText(QString::fromStdString(countWord->getTextOrg()));
}

void MainWindow::on_actionChanged_to_be_used_in_the_Hashtable_triggered()
{
    if(countWord) ui->textEdit->setText(QString::fromStdString(' ' + countWord->getText()));
}

void MainWindow::on_actionVocabulary_triggered()
{
    try
    {
        if(countWord)
        {
            try
            {
                countWord->countWord();
            }
            catch(string &e)
            {
                QMessageBox::information(this, "Aviso", QString::fromStdString(e));
            }
            QMessageBox::information(this, "information", "For easy viewing, use the right button to filter the words");
            DlgVocabulary::showVocabulary(__null, countWord);        }
        else
            throw string("Without text.");
    }
    catch(string &e)
    {
        QMessageBox::information(this, "Aviso", QString::fromStdString(e));
    }
}

void MainWindow::fineWord()
{
    QString strWord = lineEditFind->text();
    if(strWord.isEmpty())
    {
        labelStatus->setText("");
        return;
    }
    QString strText = ui->textEdit->toPlainText();
    strWord = strWord.toUpper();
    labelStatus->setText("Quantidade de palavras encontradas: " + QString::number(strText.count(' ' + strWord + ' ')));
    strText.replace(' ' + strWord + ' ', "<font color=\"red\"><b> " + strWord + " </b></font>");
    ui->textEdit->setHtml(' ' + strText);
}

void MainWindow::clickLineFind(int i, int)
{
    if(countWord && i == -1)
        ui->textEdit->setText(QString::fromStdString(' ' + countWord->getText()));
}

void MainWindow::closeEvent(QCloseEvent *)
{
    DlgVocabulary::closeVocabulary();
}
