#include "vehicleitem.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QtMath>
#include <iostream>

vehicleItem::vehicleItem(mainView *viewWidget, qreal w, qreal h)
    : view(viewWidget),
      width(w),
      height(h)
{
    view->scene()->addItem(this);
}

QRectF vehicleItem::boundingRect() const
{
    return QRectF(-5, -5, 10, 10);
}

void vehicleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkRed);
    painter->drawRect(-width/2, -height/2, width, height);
}

void vehicleItem::updateLocation(qreal xHead, qreal yHead, qreal xTail, qreal yTail)
{
    yTail = -yTail;
    yHead = -yHead;
    setPos((xTail + xHead) / 2, (yTail + yHead) / 2);
//    std::cout << qAtan2(xHead - xTail, yHead - yTail) << std::endl;
    setRotation(qRadiansToDegrees(-qAtan2(xHead - xTail, yHead - yTail)));
}

