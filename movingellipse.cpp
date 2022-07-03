#include "movingellipse.h"

MovingEllipse::MovingEllipse(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

QRectF MovingEllipse::boundingRect() const
{
    return QRectF (-8,-8,16,16);
}

void MovingEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawEllipse(-8,-8,16,16);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MovingEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit Moved();
    this->setPos(mapToScene(event->pos()));
}

void MovingEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MovingEllipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
MovingEllipse::~MovingEllipse()
{

}
