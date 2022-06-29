#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene{parent} {}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouse) {
  if (points.size() < 4) {
    points.push_back(mouse->scenePos());
    if (points.size() == 1) {
      QGraphicsTextItem *text = addText("1");
      text->setPos(points.last().x() + 10, points.last().y() + 10);
    }
    if (points.size() == 3) {
      QGraphicsTextItem *text = addText("2");
      text->setPos(points.last().x() + 10, points.last().y() + 10);
    }
  }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) {
  if (points.size() < 6) {
    QPen pen(Qt::green);
    QBrush brush(Qt::green);
    addEllipse(points.last().x() - 5, points.last().y() - 5, 10, 10, pen,
               brush);

    if (points.size() < 4) {
      QPen red(Qt::black);
      red.setWidth(3);
      addLine(points.last().x(), points.last().y(), mouse->scenePos().x(),
              mouse->scenePos().y(), red);
      points.push_back(mouse->scenePos());
      addEllipse(points.last().x() - 5, points.last().y() - 5, 10, 10, pen,
                 brush);
    }
  }
  if (points.size() == 4)
    findCrossing();
  if (points.size() == 5) {
  }
}

void Scene::findCrossing() {
  QPointF cross;
  cross.setX(
      -((points[0].x() * points[1].y() - points[1].x() * points[0].y()) *
            (points[3].x() - points[2].x()) -
        (points[2].x() * points[3].y() - points[3].x() * points[2].y()) *
            (points[1].x() - points[0].x())) /
      ((points[0].y() - points[1].y()) * (points[3].x() - points[2].x()) -
       (points[2].y() - points[3].y()) * (points[1].x() - points[0].x())));

  cross.setY(((points[2].y() - points[3].y()) * (-cross.x()) -
              (points[2].x() * points[3].y() - points[3].x() * points[2].y())) /
             (points[3].x() - points[2].x()));
    QPen pen(Qt::red);
    QBrush brush(Qt::red);
    addEllipse(cross.x() - 8, cross.y() - 8, 16, 16, pen, brush);
}

