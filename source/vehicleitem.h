#ifndef VEHICLEITEM_H
#define VEHICLEITEM_H

#include "mainview.h"

#include <QGraphicsItem>
#include <QGraphicsView>

class vehicleItem : public QGraphicsItem
{
//    friend class CityFlow::Vehicle;
public:
    vehicleItem(mainView* viewWidget, qreal w, qreal h);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void updateLocation(qreal xTail, qreal yTail, qreal xHead, qreal yHead);

//protected:
    mainView *view;
private:
    qreal width, height;
};

#endif // VEHICLEITEM_H