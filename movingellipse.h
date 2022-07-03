#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QPainter>

class MovingEllipse : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MovingEllipse(QObject *parent = 0);
    ~MovingEllipse();
signals:
    void Moved();
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

