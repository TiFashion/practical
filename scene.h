#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
public:
  explicit Scene(QObject *parent = nullptr);
  QVector<QPointF> points;
  double getDist(QPointF p1, QPointF p2);

private:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;

  double vectorMul(double ax, double ay, double bx, double by);
  void findCrossing();
  bool haveCrossPoint();
  double dist(double ax, double ay, double bx, double by);
  void Normal(QPointF p1, QPointF p2, QPointF p3);
};
