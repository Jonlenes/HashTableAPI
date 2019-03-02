#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CountWord.h"
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_actionOpen_triggered();

    void on_actionLocalizar_triggered();

    void on_actionQuit_triggered();

    void on_actionOriginal_triggered();

    void on_actionChanged_to_be_used_in_the_Hashtable_triggered();

    void on_actionVocabulary_triggered();

    void fineWord();

    void clickLineFind(int, int);

private:
    Ui::MainWindow *ui;
    CountWord *countWord;
    QLineEdit *lineEditFind;
    QLabel *labelStatus;
};

#endif // MAINWINDOW_H
