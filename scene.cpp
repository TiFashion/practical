#include "scene.h"

#include <qdebug.h>

Scene::Scene(QObject *parent) : QGraphicsScene{parent} {

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouse) {
    if (points.size() < 4) {
      points.push_back(mouse->scenePos());
      MovingEllipse* ellipse = new MovingEllipse();
      ellipse->setPos(points.last());
      ElliplesVector.push_back(ellipse);
      ellipse->setZValue(1);
      addItem(ellipse);
      if(points.size()==2)
          Lines.push_back(addLine(QLine(ElliplesVector[0]->pos().toPoint(), ElliplesVector[1]->pos().toPoint()), QPen(Qt::black,3)));
      if (points.size() == 4)
      {
        for(auto const& i: ElliplesVector)
            QObject::connect(i,SIGNAL(Moved()),this,SLOT(paintCross()));
        if(haveCrossPoint())
        {
            findCrossing();
            c = addEllipse(cross.x() - 8, cross.y() - 8, 16, 16, QPen(Qt::red), QBrush(Qt::red));
            c->setZValue(1);
        }
        Lines.push_back(addLine(QLine(ElliplesVector[2]->pos().toPoint(), ElliplesVector[3]->pos().toPoint()), QPen(Qt::black,3)));
      }
    }
      if (points.size() == 4)
      {
          paintCross();
      }
}

void Scene::paintCross()
{
    if(c!=nullptr) removeItem(c);
    for(auto const& i: Lines)
        removeItem(i);
    Lines.push_back(addLine(QLine(ElliplesVector[0]->pos().toPoint(), ElliplesVector[1]->pos().toPoint()), QPen(Qt::black,3)));
    Lines.push_back(addLine(QLine(ElliplesVector[2]->pos().toPoint(), ElliplesVector[3]->pos().toPoint()), QPen(Qt::black,3)));
    if(haveCrossPoint())
    {
        findCrossing();
        c = addEllipse(cross.x() - 8, cross.y() - 8, 16, 16, QPen(Qt::red), QBrush(Qt::red));
        c->setZValue(1);
    }
    else
        c = nullptr;
}

double Scene::vectorMul(double ax, double ay, double bx, double by) {
  return ax * by - bx * ay;
}

void Scene::findCrossing() {
  cross.setX(
      -((ElliplesVector[0]->pos().x() * ElliplesVector[1]->pos().y() - ElliplesVector[1]->pos().x() * ElliplesVector[0]->pos().y()) *
            (ElliplesVector[3]->pos().x() - ElliplesVector[2]->pos().x()) -
        (ElliplesVector[2]->pos().x() * ElliplesVector[3]->pos().y() - ElliplesVector[3]->pos().x() * ElliplesVector[2]->pos().y()) *
            (ElliplesVector[1]->pos().x() - ElliplesVector[0]->pos().x())) /
      ((ElliplesVector[0]->pos().y() - ElliplesVector[1]->pos().y()) * (ElliplesVector[3]->pos().x() - ElliplesVector[2]->pos().x()) -
       (ElliplesVector[2]->pos().y() - ElliplesVector[3]->pos().y()) * (ElliplesVector[1]->pos().x() - ElliplesVector[0]->pos().x())));

  cross.setY(((ElliplesVector[2]->pos().y() - ElliplesVector[3]->pos().y()) * (-cross.x()) -
              (ElliplesVector[2]->pos().x() * ElliplesVector[3]->pos().y() - ElliplesVector[3]->pos().x() * ElliplesVector[2]->pos().y())) /
             (ElliplesVector[3]->pos().x() - ElliplesVector[2]->pos().x()));
}

bool Scene::haveCrossPoint() {
  double v1 =
      vectorMul(ElliplesVector[3]->pos().x() - ElliplesVector[2]->pos().x(), ElliplesVector[3]->pos().y() - ElliplesVector[2]->pos().y(),
                ElliplesVector[0]->pos().x() - ElliplesVector[2]->pos().x(), ElliplesVector[0]->pos().y() - ElliplesVector[2]->pos().y());

  double v2 =
      vectorMul(ElliplesVector[3]->pos().x() - ElliplesVector[2]->pos().x(), ElliplesVector[3]->pos().y() - ElliplesVector[2]->pos().y(),
                ElliplesVector[1]->pos().x() - ElliplesVector[2]->pos().x(), ElliplesVector[1]->pos().y() - ElliplesVector[2]->pos().y());

  double v3 =
      vectorMul(ElliplesVector[1]->pos().x() - ElliplesVector[0]->pos().x(), ElliplesVector[1]->pos().y() - ElliplesVector[0]->pos().y(),
                ElliplesVector[2]->pos().x() - ElliplesVector[0]->pos().x(), ElliplesVector[2]->pos().y() - ElliplesVector[0]->pos().y());

  double v4 =
      vectorMul(ElliplesVector[1]->pos().x() - ElliplesVector[0]->pos().x(), ElliplesVector[1]->pos().y() - ElliplesVector[0]->pos().y(),
                ElliplesVector[3]->pos().x() - ElliplesVector[0]->pos().x(), ElliplesVector[3]->pos().y() - ElliplesVector[0]->pos().y());

  if ((v1 * v2 < 0) && (v3 * v4 < 0))
    return true;
  else
    return false;
}

