#ifndef WIDGET_H
#define WIDGET_H
#include "engine.h"


#include <QWidget>
#include <string>

//QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
//QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void animate();
    void simStep();

private:
    Ui::Widget *ui;
    CityFlow::Engine* eng;
    long long stepCount;
};
#endif // WIDGET_H