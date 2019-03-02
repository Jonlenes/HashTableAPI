#include "GridWidget.h"
#include <QInputDialog>

GridWidget::GridWidget(QWidget *parent) : QTableWidget(parent)
{

}

GridWidget::~GridWidget()
{

}

void GridWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        QString strFind = QInputDialog::getText(this, "Find", "Filter columns").toUpper();
        int headerCount = this->columnCount();
        QString headerText;

        for(int i = 0; i < headerCount; i++)
            this->showColumn(i);

        if(strFind.isEmpty()) return;

        for(int i = 0; i < headerCount; i++)
        {
            headerText = this->horizontalHeaderItem(i)->text();
            if(headerText != strFind)
                this->hideColumn(i);
        }
    }
    else
        QTableWidget::mousePressEvent(e);
}
