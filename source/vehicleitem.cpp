#include "vehicleitem.h"

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QPainter>
#include <QtMath>
#include <iostream>

vehicleItem::vehicleItem(mainView *viewWidget)
    : view(viewWidget)
{
    view->scene()->addItem(this);
    isDriving = false;
}

QRectF vehicleItem::boundingRect() const
{
    return QRectF(-5, -5, 10, 10);
}

void vehicleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isDriving) {
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor::fromRgb(QRandomGenerator::global()->generate()));
        painter->drawRect(-1, -3, 2, 6);
    }
}

void vehicleItem::updateLocation(qreal xHead, qreal yHead, qreal xTail, qreal yTail)
{
    isDriving = true;
    yTail = -yTail;
    yHead = -yHead;
    setPos((xTail + xHead) / 2, (yTail + yHead) / 2);
    std::cout << pos().rx() << " " << pos().ry() << std::endl;
    setRotation(qRadiansToDegrees(-qAtan2(xHead - xTail, yHead - yTail)));
}

