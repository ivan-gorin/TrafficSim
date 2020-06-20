#include "mainview.h"

mainView::mainView(QWidget* parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-50000, -50000, 100000, 100000);
    setScene(scene);
}
