#include "roaditem.h"

#include <iostream>


roadItem::roadItem(mainView *view, std::vector<CityFlow::Point> points, double width, std::string type, QGraphicsItem* parent) :
    QGraphicsPathItem(parent)
{
//    std::cout << type << std::endl;
    QPainterPath* x = new QPainterPath;
    x->moveTo(points[0].x, -points[0].y);
    for (size_t i = 1; i < points.size(); ++i) {
        x->lineTo(points[i].x, -points[i].y);
    }
    x->closeSubpath();
    this->setPath(*x);
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    if (type == "intersection") {
        this->setPen(Qt::NoPen);
        this->setBrush(QColor(128, 126, 120));
        view->scene()->addItem(this);
    } else {
        if (type == "road") {
            pen.setColor(QColor(92, 94, 88));
            pen.setWidthF(width);
            view->scene()->addItem(this);
        } else if (type == "midline") {
            pen.setColor(QColor(255, 255, 255));
            pen.setWidthF(0.5);
        } else if (type == "dotline") {
            pen.setColor(QColor(255, 255, 255));
            pen.setWidthF(0.5);
            QVector<qreal> dash(2, 2);
            pen.setDashPattern(dash);
        }
        this->setPen(pen);

    }
//    view->scene()->addItem(this);
    if (type == "road") {
        new roadItem(view, points, 0, "midline", this);
    }
}
