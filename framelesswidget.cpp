#include "framelesswidget.h"
#include <QMouseEvent>

FramelessWidget::FramelessWidget(QWidget *parent)
    : QWidget(parent),
      mouse_pressed_(false)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setMouseTracking(true);
}

FramelessWidget::~FramelessWidget()
{

}

void FramelessWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_pressed_ = true;
        move_point_ = event->pos();
    }
}

void FramelessWidget::mouseReleaseEvent(QMouseEvent *)
{
    mouse_pressed_ = false;
}

void FramelessWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_pressed_) {
        QPoint move_pos = event->globalPos();
        this->move(move_pos - move_point_);
    }
}
