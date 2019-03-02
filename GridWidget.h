#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QTableWidget>
#include <QMouseEvent>

class GridWidget : public QTableWidget
{
public:
    GridWidget(QWidget *parent = 0);
    ~GridWidget();

protected:
    void mousePressEvent(QMouseEvent *);
};

#endif // GRIDWIDGET_H
