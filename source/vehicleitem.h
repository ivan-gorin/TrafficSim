#ifndef VEHICLEITEM_H
#define VEHICLEITEM_H

#include "mainview.h"

#include <string>
#include <QGraphicsItem>
#include <QGraphicsView>

class vehicleItem : public QGraphicsItem
{
private:
    bool isDriving;
    QColor myColor;
    std::string myId;
    QRectF rect;

public:
    vehicleItem(mainView* viewWidget, std::string id, double w, double l);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void updateLocation(qreal xTail, qreal yTail, qreal xHead, qreal yHead);

//protected:
    mainView *view;
};

#endif // VEHICLEITEM_H
