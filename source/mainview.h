#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include <QGraphicsView>

class mainView : public QGraphicsView
{
public:
    mainView(QWidget* parent = nullptr);
};

#endif // MAINVIEW_H
