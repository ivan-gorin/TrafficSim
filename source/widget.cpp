#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

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
    eng->setInterval(ui->chooseIntervalBox->value());
}
