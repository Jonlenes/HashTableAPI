#ifndef DLGVOCABULARY_H
#define DLGVOCABULARY_H

#include <QDialog>
#include <QMouseEvent>
#include "CountWord.h"

namespace Ui {
class DlgVocabulary;
}

class DlgVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit DlgVocabulary(QWidget *parent = 0);
    ~DlgVocabulary();

    static void showVocabulary(QWidget *parent, CountWord *countWord);
    static void closeVocabulary();


private:
    Ui::DlgVocabulary *ui;
    static DlgVocabulary *dialog;
};

#endif // DLGVOCABULARY_H
