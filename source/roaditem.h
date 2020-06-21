#ifndef ROADITEM_H
#define ROADITEM_H

#include "mainview.h"
#include "utility.h"

#include <QGraphicsPathItem>
#include <vector>
#include <string>

class roadItem : public QGraphicsPathItem
{
public:
    roadItem(mainView* view, std::vector<CityFlow::Point> points, double width, std::string type, QGraphicsItem* parent=nullptr);
};

#endif // ROADITEM_H
