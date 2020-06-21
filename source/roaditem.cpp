#include "roaditem.h"

#include <iostream>
#include <QtMath>


roadItem::roadItem(mainView *view, std::vector<CityFlow::Point> points, double width, std::string type, QGraphicsItem* parent) :
    QGraphicsPathItem(parent)
{
    for (size_t i = 0; i < points.size(); ++i) {
        points[i].y *= -1;
    }
    myPath = new QPainterPath();
    if (type == "intersection") {
        myPath->moveTo(points[0].x, points[0].y);
        for (size_t i = 1; i < points.size(); ++i) {
            myPath->lineTo(points[i].x, points[i].y);
        }
        myPath->closeSubpath();
        this->setPath(*myPath);
        this->setPen(Qt::NoPen);
        this->setBrush(QColor(128, 126, 120));
        view->scene()->addItem(this);
    } else {
        QPen pen;
        if (type == "road") {
            QPointF direction(points[0].y - points.back().y, -(points[0].x - points.back().x));
            qreal len = qSqrt(direction.rx() * direction.rx() + direction.ry() * direction.ry());
            direction.setX(direction.x() / len);
            direction.setY(direction.y() / len);
            myPath->moveTo(points[0].x, points[0].y);
            myPath->lineTo(points.back().x, points.back().y);
            myPath->lineTo(points.back().x + direction.rx() * width, points.back().y + direction.ry() * width);
            myPath->lineTo(points[0].x + direction.rx() * width, points[0].y + direction.ry() * width);
            myPath->closeSubpath();
            this->setPath(*myPath);
            this->setPen(Qt::NoPen);
            this->setBrush(QColor(92, 94, 88));
            view->scene()->addItem(this);

        } else if (type == "midline") {
            pen.setCapStyle(Qt::FlatCap);
            pen.setColor(QColor(255, 255, 255));
            pen.setWidthF(0.5);
            myPath->moveTo(points[0].x, points[0].y);
            myPath->lineTo(points[1].x, points[1].y);
            myPath->closeSubpath();
            this->setPath(*myPath);
            this->setPen(pen);
            this->setBrush(Qt::NoBrush);
        } else if (type == "dotline") {
            QPointF direction(points[0].y - points.back().y, -(points[0].x - points.back().x));
            qreal len = qSqrt(direction.rx() * direction.rx() + direction.ry() * direction.ry());
            direction.setX(direction.x() / len);
            direction.setY(direction.y() / len);
            myPath->moveTo(points[0].x + direction.rx() * width, points[0].y + direction.ry() * width);
            myPath->lineTo(points.back().x + direction.rx() * width, points.back().y + direction.ry() * width);
            this->setPath(*myPath);
            pen.setColor(QColor(255, 255, 255));
            pen.setWidthF(0.5);
            QVector<qreal> dash{5, 5};
            pen.setDashPattern(dash);
            pen.setCapStyle(Qt::FlatCap);
            this->setPen(pen);
            this->setBrush(Qt::NoBrush);
        }
    }
}

roadItem::~roadItem()
{
    delete myPath;
}
