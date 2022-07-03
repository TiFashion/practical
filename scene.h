#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "movingellipse.h"

class Scene : public QGraphicsScene
{
Q_OBJECT
public:
  explicit Scene(QObject *parent = nullptr);
  QPointF cross;
  QGraphicsEllipseItem* c = nullptr;
  QVector<QPointF> points;
  QVector<MovingEllipse*> ElliplesVector;
  QVector<QGraphicsLineItem*> Lines;
public slots:
  void paintCross();

private:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
  double vectorMul(double ax, double ay, double bx, double by);
  void findCrossing();
  bool haveCrossPoint();
};
