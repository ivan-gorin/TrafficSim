#include "vehicleitem.h"

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QPainter>
#include <QtMath>
#include <iostream>

vehicleItem::vehicleItem(mainView *viewWidget, std::string id, double w, double l)
    : myColor(QColor::fromRgb(QRandomGenerator::global()->generate())), view(viewWidget), rect(-(w/2), -(l/2), w, l)
{
    myId = id;
    view->scene()->addItem(this);
    isDriving = false;
//    std::cout << "veh created" << std::endl;
}

QRectF vehicleItem::boundingRect() const
{
    return rect;
}

void vehicleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isDriving) {
//        std::cout << myId << " paint" << std::endl;
        painter->setPen(Qt::NoPen);
        painter->setBrush(myColor);
//        QRectF rect(-(width / 2), -(length / 2), width, length);
        painter->drawRect(rect);
    }
}

void vehicleItem::updateLocation(qreal xHead, qreal yHead, qreal xTail, qreal yTail)
{
    isDriving = true;
    yTail = -yTail;
    yHead = -yHead;
    setPos((xTail + xHead) / 2, (yTail + yHead) / 2);
//    std::cout << pos().rx() << " " << pos().ry() << std::endl;
    setRotation(qRadiansToDegrees(-qAtan2(xHead - xTail, yHead - yTail)));
    this->update();
}
