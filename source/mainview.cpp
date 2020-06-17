#include "mainview.h"

mainView::mainView(QWidget* parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-5000, -5000, 10000, 10000);
    setScene(scene);
}
