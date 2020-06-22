#include "widget.h"
#include "ui_widget.h"
#include "roaditem.h"

#include <QTimer>
#include <iostream>

#include <vector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , doStep(false)
{
    ui->setupUi(this);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    eng = new CityFlow::Engine("config.json", 1, ui->graphicsView);
    simTimer = new QTimer(this);
    connect(simTimer, &QTimer::timeout, this, &Widget::simStep);
    stepCount = 0;
    simTimer->start(16);
}

Widget::~Widget()
{
    delete ui;
    delete eng;
    delete simTimer;
}

void Widget::simStep()
{
//    std::cout << stepCount << std::endl;
    if (doStep) {
        eng->nextStep();
        ++stepCount;
    }
}

void Widget::on_zoomOutButton_clicked()
{
    ui->graphicsView->scale(0.5, 0.5);
}

void Widget::on_zoomInButton_clicked()
{
    ui->graphicsView->scale(2, 2);
}

void Widget::on_setIntervalButton_clicked()
{
    double new_int = (ui->chooseIntervalBox->value()) / 62.5;
    eng->setInterval(new_int);
}

void Widget::on_pauseButton_clicked()
{
    doStep = !doStep;
}
