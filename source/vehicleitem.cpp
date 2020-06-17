#include "vehicleitem.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QtMath>
#include <iostream>

vehicleItem::vehicleItem(mainView *viewWidget)
    : view(viewWidget)
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
    painter->drawRect(-1, -3, 2, 6);
}

void vehicleItem::updateLocation(qreal xHead, qreal yHead, qreal xTail, qreal yTail)
{
    yTail = -yTail;
    yHead = -yHead;
    setPos((xTail + xHead) / 2, (yTail + yHead) / 2);
//    std::cout << qAtan2(xHead - xTail, yHead - yTail) << std::endl;
    setRotation(qRadiansToDegrees(-qAtan2(xHead - xTail, yHead - yTail)));
}

