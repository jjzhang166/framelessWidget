#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>

class FramelessWidget : public QWidget
{
    Q_OBJECT

public:
    FramelessWidget(QWidget *parent = 0);
    ~FramelessWidget();

protected:
    QPoint move_point_;
    bool mouse_pressed_;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // FRAMELESSWIDGET_H
