#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    CityFlow::Engine eng("config.json", 1);
    eng = new CityFlow::Engine("config.json", 1, ui->graphicsView);
    QTimer* frameTimer = new QTimer(this);
    QTimer* simTimer = new QTimer(this);
    connect(frameTimer, &QTimer::timeout, this, &Widget::animate);
    connect(simTimer, &QTimer::timeout, this, &Widget::simStep);
//    frameTimer->start(15);
    stepCount = 0;
    simTimer->start(15);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::animate()
{
    std::cout << "new frame" << std::endl;

}

void Widget::simStep()
{
    std::cout << stepCount << std::endl;
    eng->nextStep();
    ++stepCount;
}
