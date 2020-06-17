#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    vehicleItem* test = new vehicleItem(ui->graphicsView);
//    test->setPos(0, 0);
    eng = new CityFlow::Engine("config.json", 1, ui->graphicsView);
    QTimer* frameTimer = new QTimer(this);
    QTimer* simTimer = new QTimer(this);
    connect(frameTimer, &QTimer::timeout, this, &Widget::animate);
    connect(simTimer, &QTimer::timeout, this, &Widget::simStep);
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
